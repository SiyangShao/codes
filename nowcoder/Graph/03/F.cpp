#include <bits/stdc++.h>
using namespace std;
struct Tarjan {
    int n, _t, edg_id;
    vector<vector<int>> E, child;
    vector<pair<int, int>> edges;
    vector<int> dfn, low, fa;
    vector<bool> cut;
    Tarjan(int _n, int m = -1) {
        n = _n, edg_id = _t = 0;
        E.resize(n), child.resize(n), dfn.assign(n, -1), low.resize(n),
            fa.assign(n, -1), cut.assign(n, false);
    }
    void addEdge(int u, int v) {
        edges.emplace_back(u, v), E[u].emplace_back(edg_id),
            E[v].emplace_back(edg_id);
        edg_id++;
    }
    void dfs(int u, int fa_id) {
        low[u] = dfn[u] = _t++;
        for (auto id : E[u]) {
            auto v = edges[id].first ^ edges[id].second ^ u;
            if (id == fa_id)
                continue;
            if (dfn[v] != -1) {
                low[u] = min(low[u], dfn[v]);
            } else {
                fa[v] = u;
                dfs(v, id);
                child[u].emplace_back(v), low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u])
                    cut[u] = true;
            }
        }
        if (fa_id == -1)
            cut[u] = child[u].size() > 1;
    }
    void solve() {
        int st = 0;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1)
                st++, dfs(i, -1);
        }
        assert(st == 1);
        auto bcc = BCC_edge();
        vector<int> in_bcc(n);
        for (int i = 0; i < bcc.size(); ++i) {
            for (auto j : bcc[i]) {
                in_bcc[j] = i;
            }
        }
        vector<int> con(bcc.size(), 0);
        for (auto [u, v] : edges) {
            if (is_bridge(u, v)) {
                con[in_bcc[u]]++, con[in_bcc[v]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < bcc.size(); ++i) {
            if (con[i] == 1) {
                ans++;
            }
        }
        cout << (ans + 1) / 2 << "\n";
    }
    bool is_cut(int u) { return cut[u]; }
    vector<vector<int>> BCC_point() {
        vector<vector<int>> BCC;
        vector<int> tmp;
        vector<bool> vis(n, false);
        stack<int> st;
        function<void(int)> dfs = [&](int u) {
            st.emplace(u), vis[u] = true;
            for (auto v : child[u]) {
                dfs(v);
                if (low[v] >= dfn[u]) {
                    tmp.clear();
                    while (!st.empty() && st.top() != v) {
                        tmp.emplace_back(st.top());
                        st.pop();
                    }
                    tmp.emplace_back(st.top());
                    st.pop(), tmp.emplace_back(u);
                    BCC.emplace_back(tmp);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (child[i].empty())
                    BCC.emplace_back(vector{i});
                dfs(i);
            }
        }
        return BCC;
    }
    bool is_bridge(int id) {
        return is_bridge(edges[id].first, edges[id].second);
    }
    bool is_bridge(int u, int v) { // assert there's an edge u-v
        if (dfn[u] > dfn[v])
            swap(u, v);
        return low[v] > dfn[u];
    }
    vector<vector<int>> BCC_edge() {
        vector<vector<int>> BCC;
        vector<int> tmp;
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true, tmp.emplace_back(u);
            for (auto v : child[u])
                if (!is_bridge(u, v))
                    dfs(v);
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                tmp.clear();
                dfs(i);
                BCC.emplace_back(tmp);
            }
        }
        return BCC;
    }
};
auto solve() {
    int n, m;
    cin >> n >> m;
    Tarjan G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.addEdge(u, v);
    }
    G.solve();
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