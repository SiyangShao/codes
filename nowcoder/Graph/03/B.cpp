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
        n = _n;
        sc_id = edg_id = _t = 0;
        E.resize(n), dfn.assign(n, -1), low.resize(n), in_scc.assign(n, -1),
            in_st.assign(n, false);
        while (!st.empty())
            st.pop();
    }
    void addEdge(int u, int v) {
        edges.emplace_back(u, v);
        E[u].emplace_back(edg_id);
        // E[v].emplace_back(edg_id);
        edg_id++;
    }
    void dfs(int u) {
        low[u] = dfn[u] = _t;
        _t++;
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
    Tarjan G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == v)
            continue;
        u--, v--;
        G.addEdge(u, v);
    }
    G.solve();
    vector<vector<int>> E(G.sc_id);
    vector<int> in(G.sc_id, 0);
    for (auto &[u, v] : G.edges) {
        if (G.in_scc[u] == G.in_scc[v])
            continue;
        E[G.in_scc[u]].emplace_back(G.in_scc[v]);
        in[G.in_scc[u]]++;
    }
    int ans = 0, fi = -1;
    for (int i = 0; i < G.sc_id; ++i) {
        if (in[i] == 0) {
            ans++;
            fi = i;
        }
    }
    if (ans == 1)
        cout << G.scc[fi].size() << "\n";
    else {
        cout << "0\n";
    }
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