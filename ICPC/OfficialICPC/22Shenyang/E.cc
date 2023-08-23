#include <bits/stdc++.h>
using namespace std;
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
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll N = 5000;
constexpr ll max_len = N * N;
array<ll, max_len + 1> bs2;
ll qpow(ll x, ll y) {
  if (x == 2 && y <= max_len)
    return bs2[y];
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
void init() {
  bs2[0] = 1;
  for (ll i = 1; i <= max_len; ++i) {
    bs2[i] = bs2[i - 1] * 2 % MOD;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int n, m;
  cin >> n >> m;
  Tarjan_BCC G(n);
  // if (n == 2) {
  //   cout << "0\n";
  //   return 0;
  // }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.addEdge(u, v);
  }
  G.solve();
  auto BCC = G.BCC_edge();
  vector<int> in_BCC(n);
  vector<int> size(BCC.size()), num_edg(BCC.size());
  for (int i = 0; i < (int)BCC.size(); ++i) {
    for (auto &j : BCC[i]) {
      in_BCC[j] = i;
      size[i]++;
    }
  }
  vector<vector<int>> E(BCC.size());
  for (auto &[u, v] : G.edges) {
    if (in_BCC[u] != in_BCC[v]) {
      E[in_BCC[u]].emplace_back(in_BCC[v]);
      E[in_BCC[v]].emplace_back(in_BCC[u]);
    } else {
      num_edg[in_BCC[u]]++;
    }
  }
  vector dp(BCC.size(), vector<ll>(n + 1, 0));
  function<void(int, int)> dfs = [&](int u, int fa) {
    dp[u][size[u]] = bs2[size[u] * (size[u] - 1) / 2 - num_edg[u]];
    dp[u][size[u]] %= MOD;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      vector<ll> nxt(size[u] + size[v] + 1);
      for (int i = 1; i <= size[u]; ++i) {
        for (int j = 1; j <= size[v]; ++j) {
          // connect u and v. Has 2^{i*j-1} ways
          nxt[i + j] =
              (nxt[i + j] + dp[u][i] * dp[v][j] % MOD * bs2[i * j - 1] % MOD) %
              MOD;
          // not connect u and v. Only 1 
          nxt[i] = (nxt[i] - dp[u][i] * dp[v][j] % MOD + MOD) % MOD;
        }
      }
      size[u] += size[v];
      for (ll i = 1; i <= size[u]; ++i) {
        dp[u][i] = nxt[i];
      }
    }
  };
  dfs(0, 0);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[0][i]) % MOD;
  }
  cout << ans << "\n";
}