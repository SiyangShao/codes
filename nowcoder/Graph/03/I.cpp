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
auto solve() {
    int n;
    cin >> n;
    Tarjan G(n * 2);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int u;
            cin >> u;
            u += n - 1;
            G.addEdge(i, u);
        }
    }
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        G.addEdge(i + n, u - 1);
    }
    G.solve();
    for (int i = 0; i < n; ++i) {
        priority_queue<int, vector<int>, greater<>> Q;
        for (auto id : G.E[i]) {
            auto v = G.edges[id].second;
            if (G.in_scc[v] == G.in_scc[i]) {
                Q.emplace(v - n + 1);
            }
        }
        cout << Q.size();
        while (!Q.empty()) {
            cout << " " << Q.top();
            Q.pop();
        }
        cout << "\n";
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