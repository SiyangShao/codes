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
    edges.emplace_back(u, v), E[u].emplace_back(edg_id++);
  }
  void dfs(int u) {
    low[u] = dfn[u] = _t++;
    st.emplace(u), in_st[u] = true;
    for (auto id : E[u]) {
      auto v = edges[id].second;
      if (dfn[v] == -1)
        dfs(v), low[u] = min(low[u], low[v]);
      else if (in_st[v])
        low[u] = min(low[u], dfn[v]);
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
    for (int i = 0; i < n; ++i)
      if (dfn[i] == -1)
        dfs(i);
  }
};
constexpr ll MOD = 1e9 + 7;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  int r, c;
  cin >> r >> c;
  vector<string> mp(r);
  int cnt = 0;
  for (auto &i : mp) {
    cin >> i;
    for (auto j : i) {
      if (j == '1')
        cnt++;
    }
  }
  if (cnt > c) {
    cout << "0\n";
    return;
  }
  Tarjan_SCC G(r * 2);
  vector<vector<int>> num(c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (mp[i][j] == '1') {
        num[j].emplace_back(i);
      }
    }
  }
  for (int x = 0; x < c; ++x) {
    int y = c - 1 - x;
    for (auto i : num[x]) {
      for (auto j : num[x]) {
        if (i == j)
          continue;
        G.addEdge(i, j + r);
        G.addEdge(i + r, j);
      }
      for (auto j : num[y]) {
        if (i == j)
          continue;
        G.addEdge(i, j);
        G.addEdge(i + r, j + r);
      }
    }
  }
  G.solve();
  for (int i = 0; i < r; ++i) {
    if (G.in_scc[i] == G.in_scc[i + r]) {
      cout << "0\n";
      return;
    }
  }
  cout << qpow(2, (ll)G.scc.size() / 2) << "\n";
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