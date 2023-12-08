#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
struct stBCC {
  int n, _t, edg_id;
  vector<vector<int>> E, child;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, fa;
  vector<bool> cut;
  stBCC(int _n)
      : n(_n), E(n), child(n), dfn(n, -1), low(n), fa(n, -1), cut(n, false) {
    edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.eb(u, v);
    E[u].eb(edg_id);
    E[v].eb(edg_id);
    edg_id++;
  }
  void dfs(int u, int fa_id) {
    low[u] = dfn[u] = _t++;
    for (auto id : E[u]) {
      auto v = edges[id].first ^ edges[id].second ^ u;
      if (id == fa_id)
        continue;
      if (dfn[v] != -1) {
        low[u] = min(low[u], dfn[v]);
      } else {
        fa[v] = u;
        dfs(v, id);
        child[u].eb(v);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          cut[u] = true;
        }
      }
    }
    if (fa_id == -1) {
      cut[u] = child[u].size() > 1;
    }
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1)
        dfs(i, -1);
    }
  }
  bool is_bridge(int u, int v) {
    if (dfn[u] > dfn[v])
      swap(u, v);
    return low[v] > dfn[u];
  }
  vector<vector<int>> BCC_edge() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
      vis[u] = true, tmp.eb(u);
      for (auto id : E[u]) {
        auto v = edges[id].first ^ edges[id].second ^ u;
        if (!is_bridge(u, v) && !vis[v])
          dfs(v);
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        tmp.clear();
        dfs(i);
        BCC.eb(tmp);
      }
    }
    return BCC;
  }
};
#define FOR(i, a, b) for (ll i = a; (i) <= (b); ++(i))
#define ROF(i, a, b) for (ll i = a; (i) >= (b); --(i))
using ll = int;
const static ll mH = 20;
const static ll maxn = 10004; // TODO

ll up[maxn][mH + 2];
ll inT[maxn], outT[maxn], depth[maxn];
ll timer = 0;

void ddfs(ll o, ll p, vector<vector<int>> &g) {
  inT[o] = ++timer, depth[o] = ((p != -1) ? depth[p] + 1 : 1),
  up[o][0] = ((p != -1) ? p : o);
  FOR(i, 1, mH)
  up[o][i] = up[up[o][i - 1]][i - 1]; // root will hop to himself, preventing
                                      // all future from hopping out
  for (auto e : g[o])
    if (e != p)
      ddfs(e, o, g);
  outT[o] = ++timer;
}

bool isAncestor(ll father, ll son) {
  return (inT[father] <= inT[son] && outT[father] >= outT[son]);
}

ll lca(ll u, ll v) {
  if (isAncestor(u, v))
    return u;
  if (isAncestor(v, u))
    return v;
  // transform into subproblem of a closer u
  ROF(i, mH, 0) if (!isAncestor(up[u][i], v)) u = up[u][i];
  return up[u][0];
}

ll dist(ll u, ll v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
int main() {
  int n, m;
  cin >> n >> m;
  stBCC G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.addEdge(u, v);
  }
  G.solve();
  auto bcc = G.BCC_edge();
  int newN = (int)bcc.size();
  vector<int> inBCC(n, -1);
  for (int i = 0; i < newN; ++i) {
    for (auto u : bcc[i])
      inBCC[u] = i;
  }
  vector<vector<int>> E(newN), topo(newN);
  for (auto [u, v] : G.edges) {
    if (inBCC[u] == inBCC[v])
      continue;
    E[inBCC[u]].emplace_back(inBCC[v]);
    E[inBCC[v]].emplace_back(inBCC[u]);
    // cout << inBCC[u] << " " << inBCC[v] << endl;
  }
  // return 0;
  ddfs(0, -1, E);
  int k;
  cin >> k;
  vector<int> add(newN, 0), del(newN, 0);
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (inBCC[u] == inBCC[v])
      continue;
    topo[inBCC[u]].emplace_back(inBCC[v]);
    int mid = lca(inBCC[u], inBCC[v]);
    add[inBCC[u]]++;
    add[mid]--;
    del[inBCC[v]]++;
    del[mid]--;
  }
  map<pair<int, int>, int> dirx, diry;
  bool can = true;
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      add[u] += add[v];
      del[u] += del[v];
    }
    if (add[u] != 0 && del[u] != 0) {
      can = false;
      return;
    }
    if (add[u] != 0) {
      dirx[{u, fa}] = 1;
      dirx[{fa, u}] = 0;
      // cout << u + 1 << " " << fa + 1 << "\n";
    } else {
      // cout << fa + 1 << " " << u + 1 << "\n";
      dirx[{u, fa}] = 0;
      dirx[{fa, u}] = 1;
    }
  };
  dfs(0, 0);
  if (!can) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  vector<int> vis(n, 0);
  function<void(int, int)> newdfs = [&](int u, int fa) {
    vis[u] = 1;
    for (auto id : G.E[u]) {
      // cout << u << " " << id << endl;
      auto v = G.edges[id].first ^ G.edges[id].second ^ u;
      // cout << u << " " << v << " " << id << endl;
      if (v == fa)
        continue;
      if (inBCC[v] != inBCC[u])
        continue;
      if (vis[v]) {
        diry[{u, v}] = 1;
        diry[{v, u}] = 0;
      } else {
        diry[{u, v}] = 0;
        diry[{v, u}] = 1;
        newdfs(v, u);
      }
    }
  };
  for (int i = 0; i < newN; ++i) {
    newdfs(bcc[i][0], bcc[i][0]);
    // for (auto u : bcc[i]) {
    //   cout << u + 1 << " ";
    // }
    // cout << endl;
  }
  for (auto [u, v] : G.edges) {
    if (inBCC[u] != inBCC[v]) {
      // cout << "x: ";
      if (dirx[{inBCC[u], inBCC[v]}]) {
        cout << u + 1 << " " << v + 1 << "\n";
      } else {
        cout << v + 1 << " " << u + 1 << "\n";
      }
    } else {
      if (diry[{u, v}]) {
        cout << u + 1 << " " << v + 1 << "\n";
      } else {
        cout << v + 1 << " " << u + 1 << "\n";
      }
    }
  }
}