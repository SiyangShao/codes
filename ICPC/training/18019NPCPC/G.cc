#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
auto solve() {
  int n;
  cin>>n;
  Tarjan G(n);
  int e;
  cin>>e;
  for(ll i = 0 ; i < e; ++i){
    int u, v;
    cin>>u>>v;
    G.addEdge(u, v);
  } 
  G.solve();
  cout<<G.scc.size()<<"\n";
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