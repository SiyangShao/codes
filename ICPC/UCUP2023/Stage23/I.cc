#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...)
#endif
using namespace std;
using ll = long long;
struct Tarjan_BCC {
  int n, _t, edg_id;
  vector<vector<int>> E, child;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, fa;
  vector<bool> cut;
  Tarjan_BCC(int _n)
      : n(_n), E(n), child(n), dfn(n, -1), low(n), fa(n, -1), cut(n, false) {
    edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id),
        E[v].emplace_back(edg_id);
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
        child[u].emplace_back(v), low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u])
          cut[u] = true;
      }
    }
    if (fa_id == -1)
      cut[u] = child[u].size() > 1;
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1)
        dfs(i, -1);
    }
  }
  bool is_cut(int u) { return cut[u]; }
  vector<vector<int>> BCC_point() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    stack<int> st;
    function<void(int)> dfs = [&](int u) {
      st.emplace(u), vis[u] = true;
      for (auto v : child[u]) {
        dfs(v);
        if (low[v] >= dfn[u]) {
          tmp.clear();
          while (!st.empty() && st.top() != v) {
            tmp.emplace_back(st.top());
            st.pop();
          }
          tmp.emplace_back(st.top());
          st.pop(), tmp.emplace_back(u);
          BCC.emplace_back(tmp);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        if (child[i].empty())
          BCC.emplace_back(vector{i});
        dfs(i);
      }
    }
    return BCC;
  }
  bool is_bridge(int id) {
    return is_bridge(edges[id].first, edges[id].second);
  }
  bool is_bridge(int u, int v) { // assert there's an edge u-v
    if (dfn[u] > dfn[v])
      swap(u, v);
    return low[v] > dfn[u];
  }
  vector<vector<int>> BCC_edge() {
    vector<vector<int>> BCC;
    vector<int> tmp;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
      vis[u] = true, tmp.emplace_back(u);
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
        BCC.emplace_back(tmp);
      }
    }
    return BCC;
  }
};
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u == fa[u])
      return u;
    return fa[u] = find(fa[u]);
  }
  void merge(int u, int v) {
    dbg("merge", u, v);
    u = find(u), v = find(v);
    fa[u] = v;
  }
  map<int, vector<int>> group() {
    map<int, vector<int>> mp;
    for (int i = 0; i < (int)fa.size(); ++i) {
      mp[find(i)].emplace_back(i);
    }
    return mp;
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  Tarjan_BCC G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.addEdge(u, v);
  }
  vector<int> a(n);
  for (auto &i : a)
    cin >> i, i--;
  vector<int> cnt(n);
  int divNum = 0;
  for (auto i : a)
    cnt[i]++;
  for (auto i : cnt)
    if (i)
      divNum++;
  dbg(cnt);
  for (int i = 1; i < n; ++i) {
    cnt[i] += cnt[i - 1];
  }
  dbg(cnt);
  assert(is_sorted(cnt.begin(), cnt.end()));
  cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());
  dbg(cnt);

  G.solve();
  auto BCC = G.BCC_edge();
  if (divNum == 1) {
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
      cout << a[0] + 1 << " ";
    }
    cout << "\n";
    return;
  }
  if (BCC.size() == 1) {
    cout << "No\n";
    return;
  }
  int BccSiz = (int)BCC.size();
  vector<int> inBcc(n);
  vector<vector<int>> E(BccSiz);
  set<pair<int, int>> st;
  for (int i = 0; i < BccSiz; ++i) {
    for (auto u : BCC[i]) {
      inBcc[u] = i;
    }
  }
  dbg(inBcc);
  for (auto [u, v] : G.edges) {
    if (inBcc[u] == inBcc[v])
      continue;
    E[inBcc[u]].emplace_back(inBcc[v]);
    E[inBcc[v]].emplace_back(inBcc[u]);
  }
  dbg(divNum);
  dbg(E);
  // int rdBegin = rand() % BccSiz;
  int rdBegin = 0;
  vector<int> siz(BccSiz, 1), chooseL(BccSiz, -1), chooseR(BccSiz, -1),
      maxL(BccSiz, -1), maxR(BccSiz, -1);
  vector<int> up(BccSiz, 0), down(BccSiz, 0);
  vector<vector<int>> downNode(divNum + 1);
  vector<vector<int>> upNode(divNum + 1);
  int rt = -1, lef = -1, rig = -1;
  function<void(int, int)> dfs = [&](int u, int fa) {
    siz[u] = (int)BCC[u].size();
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      siz[u] += siz[v];
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      assert(v != -1);
      downNode[down[v]].emplace_back(v);
      upNode[up[v]].emplace_back(v);
    }
    // Find can or not
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      int need = divNum - 1 - up[v];
      if (need == 0 && rt == -1) {
        rt = u;
        lef = chooseL[v];
        rig = -1;
      } else if (rt == -1 && down[v] == divNum - 1) {
        rt = u;
        rig = chooseR[v];
        lef = -1;
      } else if (rt == -1 && !downNode[need].empty()) {
        rt = u;
        lef = chooseL[v];
        if (v != downNode[need][0] || (int)downNode[need].size() >= 2) {
          if (v != downNode[need][0])
            rig = chooseR[downNode[need][0]];
          else
            rig = chooseR[downNode[need][1]];
        } else {
          rt = -1;
          lef = -1;
          rig = -1;
        }
      }
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      int need = divNum - 1 - down[v];
      if (need == 0 && rt == -1) {
        rt = u;
        rig = chooseR[v];
        lef = -1;
      } else if (rt == -1 && !upNode[need].empty()) {
        rt = u;
        rig = chooseR[v];
        if (v != upNode[need][0] || (int)upNode[need].size() >= 2) {
          if (v != upNode[need][0])
            lef = chooseL[upNode[need][0]];
          else
            lef = chooseL[upNode[need][1]];
        } else {
          rt = -1;
          lef = -1;
          rig = -1;
        }
      }
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      downNode[down[v]].clear();
      upNode[up[v]].clear();
    }
    // can up?
    auto it = lower_bound(cnt.begin(), cnt.end(), siz[u]);
    if (it != cnt.end() && *it == siz[u]) {
      up[u] = 1;
      chooseL[u] = u;
    }
    // can down?
    it = lower_bound(cnt.begin(), cnt.end(), n - siz[u]);
    if (it != cnt.end() && *it == n - siz[u]) {
      down[u] = 1;
      chooseR[u] = u;
    }
    dbg(fa, u, up[u], down[u]);
    int maxUp = -1, maxDown = -1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (maxUp == -1 || up[v] > up[maxUp]) {
        maxUp = v;
      }
      if (maxDown == -1 || down[v] > down[maxDown]) {
        maxDown = v;
      }
    }
    if (maxUp != -1) {
      up[u] += up[maxUp];
      if (chooseL[u] == -1)
        chooseL[u] = chooseL[maxUp];
      maxL[u] = chooseL[maxUp];
    }
    if (maxDown != -1) {
      down[u] += down[maxDown];
      if (chooseR[u] == -1)
        chooseR[u] = chooseR[maxDown];
      maxR[u] = chooseR[maxDown];
    }
  };
  dbg(rdBegin);
  dfs(rdBegin, rdBegin);
  dbg(up, down);
  dbg(rt, lef, rig);
  if (rt == -1) {
    // if (wrongTime < 5) {
    //   wrongTime++;
    //   goto FLAG;
    // }
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  dbg(maxL, maxR);
  vector<int> num;
  DSU dsu(BccSiz);
  vector<int> vis(BccSiz, 0), special(BccSiz, 0);
  function<void(int, int)> ranse = [&](int u, int c) {
    vis[u] = 1;
    if (special[u]) {
      c = u;
    }
    dsu.merge(u, c);
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      ranse(v, c);
    }
  };
  function<void(int)> buildLef = [&](int u) {
    if (u == -1)
      return;
    buildLef(maxL[u]);
    num.emplace_back(u);
  };
  function<void(int)> buildRig = [&](int u) {
    if (u == -1)
      return;
    num.emplace_back(u);
    buildRig(maxR[u]);
  };
  buildLef(lef);
  num.emplace_back(rt);
  buildRig(rig);
  for (auto i : num) {
    special[i] = 1;
  }
  ranse(rt, rt);
  dbg(num);
  map<int, int> id;
  for (int i = 0; i < (int)num.size(); ++i) {
    id[dsu.find(num[i])] = i;
  }
  dbg(dsu.fa);
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  vector<int> ans(BccSiz);
  for (int i = 0; i < BccSiz; ++i) {
    assert(id.contains(dsu.find(i)));
    ans[i] = a[id[dsu.find(i)]];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[inBcc[i]] + 1 << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  // if (_ == 83335) {
  //   for (int tcase = 0; tcase < _; ++tcase) {
  //     if (tcase == 1629) {
  //       int n, m;
  //       cin >> n >> m;
  //       cout << "1630 case :: \n";
  //       cout << n << " " << m << "\n";
  //       int u, v;
  //       for (int i = 0; i < m; ++i) {
  //         cin >> u >> v;
  //         cout << u << " " << v << "\n";
  //       }
  //       for (int i = 0; i < n; ++i) {
  //         int a;
  //         cin >> a;
  //         cout << a << " ";
  //       }
  //       cout << "\n";
  //       return 0;
  //     } else {
  //       int n, m;
  //       cin >> n >> m;
  //       int u, v;
  //       for (int i = 0; i < m; ++i) {
  //         cin >> u >> v;
  //       }
  //       for (int i = 0; i < n; ++i) {
  //         int a;
  //         cin >> a;
  //       }
  //     }
  //   }
  //   return 0;
  // }
  for (int tcase = 0; tcase < _; ++tcase) {
    solve();
  }
}