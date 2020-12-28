#include <bits/stdc++.h>
using namespace std;
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
  int k, n;
  cin >> k >> n;
  Tarjan_SCC G(k * 2);
  for (int i = 0; i < n; ++i) {
    vector<pair<int, int>> op(3);
    for (auto &[u, v] : op) {
      cin >> u;
      u--;
      string s;
      cin >> s;
      v = s[0] == 'B' ? 1 : 0;
    }
    for (int j = 0; j < 3; ++j) {
      // j is wrong
      for (int q = 0; q < 3; ++q) {
        if (j == q)
          continue;
        auto [pos_j, col_j] = op[j];
        auto [pos_k, col_k] = op[q];
        G.addEdge(pos_j + (col_j == 1 ? 0 : k), pos_k + (col_k == 1 ? k : 0));
      }
    }
  }
  G.solve();
  for (int i = 0; i < k; ++i) {
    if (G.in_scc[i] == G.in_scc[i + k]) {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < k; ++i) {
    if (G.in_scc[i] < G.in_scc[i + k]) {
      cout << "R";
    } else {
      cout << "B";
    }
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}