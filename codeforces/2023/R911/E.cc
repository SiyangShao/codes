#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct Tarjan_SCC {
  int n, edg_id, _t, sc_id;
  vector<vector<int>> E, scc;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, in_scc;
  stack<int> st;
  vector<bool> in_st;
  Tarjan_SCC(int _n)
      : n(_n), E(_n), dfn(_n, -1), low(_n), in_scc(_n, -1), in_st(_n, false) {
    sc_id = edg_id = _t = 0;
  }
  void addEdge(int u, int v) {
    edges.emplace_back(u, v), E[u].emplace_back(edg_id);
    // E[v].emplace_back(edg_id);
    edg_id++;
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto id : E[u]) {
      auto v = edges[id].second;
      if (dfn[v] == -1) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if (in_st[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      vector<int> _scc;
      _scc.clear();
      while (st.top() != u) {
        auto v = st.top();
        in_scc[v] = sc_id, _scc.emplace_back(v), in_st[v] = false;
        st.pop();
      }
      in_scc[u] = sc_id, _scc.emplace_back(u);
      scc.emplace_back(_scc);
      sc_id++;
      st.pop(), in_st[u] = false;
    }
  }
  void solve() {
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfs(i);
      }
    }
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  Tarjan_SCC E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E.addEdge(u, v);
  }
  E.solve();
  const auto &scc = E.scc;
  const auto &in_scc = E.in_scc;
  const auto &edges = E.edges;
  vector<vector<int>> G(scc.size()), revG(scc.size());
  vector<ll> dp(scc.size());
  vector<int> out(scc.size()), num(scc.size()), vis(scc.size());
  for (int i = 0; i < n; ++i) {
    dp[in_scc[i]] += a[i];
    num[in_scc[i]]++;
  }
  dbg(dp, num);
  for (auto [u, v] : edges) {
    if (in_scc[u] == in_scc[v])
      continue;
    G[in_scc[u]].emplace_back(in_scc[v]);
    revG[in_scc[v]].emplace_back(in_scc[u]);
    out[in_scc[u]]++;
  }
  dbg(G);
  queue<int> Q;
  for (int i = 0; i < (int)scc.size(); ++i) {
    if (out[i] == 0) {
      Q.emplace(i);
    }
  }
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto v : revG[u]) {
      out[v]--;
      if (out[v] == 0)
        Q.emplace(v);
    }
    pair<int, ll> cur = {0, 0};
    for (auto v : G[u]) {
      if (pair<int, ll>{num[v], -dp[v]} > cur) {
        cur = pair<int, ll>{num[v], -dp[v]};
      }
    }
    num[u] += cur.first;
    dp[u] -= cur.second;
  }

  vector<int> id(scc.size());
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    if (num[i] != num[j])
      return num[i] > num[j];
    return dp[i] < dp[j];
  });
  cout << num[id[0]] << " " << dp[id[0]] << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}