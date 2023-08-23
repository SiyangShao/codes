#include <bits/stdc++.h>
using namespace std;
struct Tarjan {
    int n, _t, edg_id;
    vector<vector<int>> E, child;
    vector<pair<int, int>> edges;
    vector<int> dfn, low, fa;
    vector<bool> cut, bridge;
    Tarjan(int _n, int m = -1) {
        n = _n;
        edg_id = _t = 0;
        E.resize(n), child.resize(n), dfn.assign(n, -1), low.resize(n),
            fa.assign(n, -1), cut.assign(n, false);
        if (m != -1) {
            bridge.assign(m, false);
        }
    }
    void addEdge(int u, int v) {
        edges.emplace_back(u, v);
        E[u].emplace_back(edg_id), E[v].emplace_back(edg_id);
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
                child[u].emplace_back(v);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    cut[u] = true;
                }
            }
        }
        if (fa_id == -1) {
            cut[u] = child[u].size() > 1;
        }
    }
    void solve() {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                dfs(i, -1);
            }
        }
    }
    bool is_cut(int u) { return cut[u]; }
    vector<vector<int>> BCC_point() {
        vector<vector<int>> BCC;
        vector<int> tmp;
        vector<bool> vis(n, false);
        stack<int> st;
        function<void(int)> dfs = [&](int u) {
            st.emplace(u);
            vis[u] = true;
            for (auto v : child[u]) {
                dfs(v);
                if (low[v] >= dfn[u]) {
                    tmp.clear();
                    while (!st.empty() && st.top() != v) {
                        tmp.emplace_back(st.top());
                        st.pop();
                    }
                    tmp.emplace_back(st.top());
                    st.pop();
                    tmp.emplace_back(u);
                    BCC.emplace_back(tmp);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (child[i].empty()) {
                    BCC.emplace_back(vector{i});
                }
                dfs(i);
            }
        }
        return BCC;
    }
    bool is_bridge(int id) {
        return is_bridge(edges[id].first, edges[id].second);
    }
    bool is_bridge(int u, int v) {
        // assert there's an edge u-v
        if (dfn[u] > dfn[v]) {
            swap(u, v);
        }
        return low[v] > dfn[u];
    }
    vector<vector<int>> BCC_edge() {
        vector<vector<int>> BCC;
        vector<int> tmp;
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            tmp.emplace_back(u);
            for (auto v : child[u]) {
                if (!is_bridge(u, v)) {
                    dfs(v);
                }
            }
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
    vector<pair<int, int>> edge(m);
    Tarjan G(n);
    for (auto &[u, v] : edge) {
        cin >> u >> v;
        u--, v--;
        G.addEdge(u, v);
    }
    G.solve();
    vector<pair<int, int>> ans;
    for (auto [u, v] : edge) {
        if (G.is_bridge(u, v)) {
            if (u > v) {
                swap(u, v);
            }
            ans.emplace_back(u, v);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto &[u, v] : ans) {
        cout << u + 1 << " " << v + 1 << "\n";
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