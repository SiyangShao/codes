#include <bits/stdc++.h>
using namespace std;
struct Tarjan {
  int n, edg_id, _t, sc_id;
  vector<vector<int>> E, scc;
  vector<pair<int, int>> edges;
  vector<int> dfn, low, in_scc;
  stack<int> st;
  vector<bool> in_st;
  Tarjan(int _n, int m = -1) {
    n = _n, sc_id = edg_id = _t = 0;
    E.resize(n), dfn.assign(n, -1), low.resize(n), in_scc.assign(n, -1),
        in_st.assign(n, false);
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
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> mp(m, vector<ll>(n));
  Tarjan G(n);
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
      j--;
    }
  }
  for (ll i = 0; i < m; ++i) {
    for (ll j = 1; j < n; ++j) {
      G.addEdge(mp[i][j - 1], mp[i][j]);
    }
  }
  G.solve();
  const auto &scc = G.scc;
  const auto &in_scc = G.in_scc;
  set<pair<ll, ll>> st;
  vector<ll> dp(scc.size(), 0), in(scc.size(), 0);
  vector<vector<ll>> E(scc.size());
  for (ll i = 0; i < m; ++i) {
    for (ll j = 1; j < n; ++j) {
      int u = mp[i][j - 1], v = mp[i][j];
      if (in_scc[u] != in_scc[v] && !st.contains({in_scc[u], in_scc[v]})) {
        E[in_scc[u]].emplace_back(in_scc[v]);
        st.emplace(in_scc[u], in_scc[v]);
        in[in_scc[v]]++;
      }
    }
  }
  function<void(ll)> dfs = [&](ll u) {
    for (auto v : E[u]) {
      dp[v] += dp[u] + scc[u].size();
      in[v]--;
      if (in[v] == 0) {
        dfs(v);
      }
    }
  };
  for (ll i = 0; i < scc.size(); ++i) {
    if (in[i] == 0) {
      dfs(i);
    }
  }
  for (ll i = 0; i < n; ++i) {
    cout << (n - dp[in_scc[i]]) - 1 << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin>>_;
  while (_--) {
    solve();
  }
}