#include <bits/stdc++.h>
using namespace std;
struct Tarjan {
    int n, _t, edg_id, x, y, ans;
    vector<vector<int>> E, child;
    vector<pair<int, int>> edges;
    vector<int> dfn, low, fa;
    vector<bool> cut;
    Tarjan(int _n, int m = -1) {
        ans = n = _n, edg_id = _t = 0;
        E.resize(n), child.resize(n), dfn.assign(n, -1), low.resize(n),
            fa.assign(n, -1), cut.assign(n, false);
    }
    void addEdge(int u, int v) {
        edges.emplace_back(u, v), E[u].emplace_back(edg_id),
            E[v].emplace_back(edg_id);
        edg_id++;
    }
    bool check(int u) {
        if (dfn[u] < dfn[x] && dfn[u] > dfn[y])
            return true;
        if (dfn[u] < dfn[y] && dfn[u] > dfn[x])
            return true;
        return false;
    }
    void dfs(int u, int fa_id) {
        low[u] = dfn[u] = _t++;
        for (auto id : E[u]) {
            auto v = edges[id].first ^ edges[id].second ^ u;
            if (dfn[v] != -1) {
                low[u] = min(low[u], dfn[v]);
            } else {
                dfs(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    cut[u] = true;
                    if (u != x && u != y && dfn[v] <= dfn[y]) {
                        ans = min(ans, u);
                    }
                }
            }
        }
    }
    void solve() {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1)
                dfs(i, -1);
        }
    }
};
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    Tarjan G(n);
    int u, v;
    while (cin >> u >> v) {
        if (u == 0 || v == 0) {
            break;
        }
        u--, v--;
        assert(u < n && v < n);
        G.addEdge(u, v);
    }
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a == b) {
        cout << "No solution";
        return 0;
    }
    G.x = a, G.y = b;
    G.dfs(a, a);
    if (G.ans < n) {
        cout << G.ans + 1;
    } else
        cout << "No solution";
}