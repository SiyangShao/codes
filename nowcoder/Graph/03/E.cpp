#include <iostream>
#include <set>
#include <stack>
#include <vector>
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
    Tarjan G(n);
    for (int i = 0; i < n; ++i) {
        int r;
        while (cin >> r) {
            if (r == 0) {
                break;
            }
            G.addEdge(i, r - 1);
        }
    }
    G.solve();
    vector<int> in(G.sc_id, 0), out(G.sc_id, 0);
    int ans1 = 0, ans2 = 0;
    set<pair<int, int>> st;
    for (auto &[u, v] : G.edges) {
        if (G.in_scc[u] != G.in_scc[v] &&
            !st.count({G.in_scc[u], G.in_scc[v]})) {
            in[G.in_scc[v]]++;
            out[G.in_scc[u]]++;
            st.insert({G.in_scc[u], G.in_scc[v]});
        }
    }
    for (int i = 0; i < G.sc_id; ++i) {
        if (!in[i]) {
            ans1++;
        }
        if (!out[i]) {
            ans2++;
        }
    }
    if (G.sc_id == 1) {
        cout << "1\n0\n";
        return;
    }
    cout << ans1 << "\n" << max(ans1, ans2) << "\n";
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