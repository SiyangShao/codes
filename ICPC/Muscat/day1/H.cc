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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  Tarjan_SCC G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.addEdge(u, v);
  }
  G.solve();
  vector<int> in(G.scc.size());
  vector<int> need;
  for (auto &[u, v] : G.edges) {
    if (G.in_scc[u] == G.in_scc[v]) {
      continue;
    }
    in[G.in_scc[v]]++;
  }
  for (int i = 0; i < (int)G.scc.size(); ++i) {
    if (in[i] == 0) {
      sort(G.scc[i].begin(), G.scc[i].end());
      need.emplace_back(G.scc[i][0] + 1);
      // for (auto j : G.scc[i]) {
      // need.emplace_back(j + 1);
      // }
    }
  }
  sort(need.begin(), need.end());
  for (auto i : need) {
    cout << i << "\n";
  }
}