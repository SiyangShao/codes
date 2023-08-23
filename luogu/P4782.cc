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
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  Tarjan_SCC G(n * 2);
  for (int i = 0; i < m; ++i) {
    int u, a, v, b;
    cin >> u >> a >> v >> b;
    u--, v--;
    G.addEdge(u + (a ^ 1) * n, v + b * n);
    G.addEdge(v + (b ^ 1) * n, u + a * n);
  }
  G.solve();
  for (int i = 0; i < n; ++i) {
    if (G.in_scc[i] == G.in_scc[i + n]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  cout << "POSSIBLE\n";
  for (int i = 0; i < n; ++i) {
    if (G.in_scc[i] < G.in_scc[i + n]) {
      cout << "0 ";
    } else {
      cout << "1 ";
    }
  }
}