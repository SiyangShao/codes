#include <bits/stdc++.h>
using namespace std;
struct Tarjan {
    using ll = long long;
    int n, _t, edg_id;
    vector<vector<int>> E, child;
    vector<pair<int, int>> edges;
    vector<int> dfn, low, fa;
    vector<bool> cut, has;
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
        ll ans1 = 0, ans2 = 1;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                dfs(i, -1);
            }
        }
        auto BCC = BCC_point();
        for (const auto &st : BCC) {
            int __cut = 0;
            for (auto j : st) {
                if (cut[j]) {
                    __cut++;
                }
            }
            if (__cut == 0) {
                ans1 += 2;
                ll sz = st.size();
                ans2 *= sz * (sz - 1) / 2;
            } else if (__cut == 1) {
                ans1++;
                ll sz = st.size();
                sz--;
                ans2 *= sz;
            }
        }
        cout << ans1 << " " << ans2 << "\n";
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
auto solve(int n) {
    vector<pair<int, int>> edg(n);
    map<int, int> mp;
    int _cnt = 0;
    for (auto &[u, v] : edg) {
        cin >> u >> v;
        if (mp.find(u) == mp.end()) {
            mp[u] = _cnt++;
        }
        if (mp.find(v) == mp.end()) {
            mp[v] = _cnt++;
        }
    }
    Tarjan G(_cnt);
    for (auto &[u, v] : edg) {
        G.addEdge(mp[u], mp[v]);
    }
    G.solve();
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    int t = 1;
    while (cin >> _) {
        if (_ == 0)
            break;
        cout << "Case " << t++ << ": ";
        solve(_);
    }
}