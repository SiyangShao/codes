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
    int n, m;
    cin >> n >> m;
    vector<int> w(n), v(n), d(n);
    for (auto &i : w) {
        cin >> i;
    }
    for (auto &i : v) {
        cin >> i;
    }
    for (auto &i : d) {
        cin >> i;
        i--;
    }
    Tarjan G(n);
    for (int i = 0; i < n; ++i) {
        if (d[i] != -1) {
            G.addEdge(d[i], i);
        }
    }
    G.solve();
    vector<int> nW(G.sc_id + 1, 0), nV(G.sc_id + 1, 0), in(G.sc_id + 1);
    for (int i = 0; i < n; ++i) {
        nW[G.in_scc[i] + 1] += w[i];
        nV[G.in_scc[i] + 1] += v[i];
    }
    set<pair<int, int>> st;
    vector<vector<int>> E(G.sc_id + 1);
    for (auto &[u, v] : G.edges) {
        if (G.in_scc[u] != G.in_scc[v] &&
            !st.count({G.in_scc[u], G.in_scc[v]})) {
            E[G.in_scc[u] + 1].emplace_back(G.in_scc[v] + 1);
            in[G.in_scc[v] + 1]++;
            st.emplace(G.in_scc[u], G.in_scc[v]);
        }
    }
    for (int i = 1; i <= G.sc_id; ++i) {
        if (!in[i]) {
            E[0].emplace_back(i);
        }
    }
    vector<vector<int>> dp(G.sc_id + 1, vector<int>(m + 10, 0));
    function<void(int)> dfs = [&](int u) {
        for (int i = nW[u]; i <= m; ++i) {
            dp[u][i] = nV[u];
        }
        // cout<<u<<" "<<dp[u][m]<<"\n";
        for (auto v : E[u]) {
            dfs(v);
            for (int j = m - nW[u]; j >= 0; --j) {
                for (int q = 0; q <= j; ++q) {
                    dp[u][j + nW[u]] =
                        max(dp[u][j + nW[u]], dp[u][j + nW[u] - q] + dp[v][q]);
                }
            }
        }
    };
    dfs(0);
    cout << dp[0][m] << "\n";
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