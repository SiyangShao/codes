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
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1)
                dfs(i, -1);
        }
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
auto solve(int n, int m) {
    Tarjan G(n);
    vector<vector<int>> mp(n, vector<int>(n, 1));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mp[u][v] = mp[v][u] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mp[i][j]) {
                G.addEdge(i, j);
            }
        }
    }
    G.solve();
    // Observation: In a BCC_point, if there exist ONE odd ring, all points in
    // BCC can be covered by at least one odd ring.
    auto BCC = G.BCC_point();
    vector<int> col(n, -1), flag(n, 0), can(n, 0);
    function<bool(int, int)> dfs = [&](int u, int c) {
        col[u] = c;
        bool flg = true;
        for (auto id : G.E[u]) {
            auto v = G.edges[id].first ^ G.edges[id].second ^ u;
            if (flag[v] != 1) {
                continue;
            }
            if (col[u] == col[v]) {
                return false;
            }
            if (col[v] == -1) {
                flg = flg && dfs(v, col[u] ^ 1);
            }
        }
        return flg;
    };
    for (const auto &bcc : BCC) {
        for (auto i : bcc) {
            flag[i] = 1;
            col[i] = -1;
        }
        if (bcc.size() >= 3 && !dfs(bcc[0], 0)) {
            for (auto v : bcc) {
                can[v] = 1;
            }
        }
        for (auto i : bcc) {
            // cout<<i+1<<" ";
            flag[i] = 0;
            col[i] = -1;
        }
        // cout<<"\n";
    }
    cout << n - accumulate(can.begin(), can.end(), 0) << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }
}