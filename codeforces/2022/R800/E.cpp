#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e16 + 7;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G, Gr;
    G.assign(n, vector<ll>());
    Gr.assign(n, vector<ll>());
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        Gr[v].emplace_back(u);
    }
    vector<ll> deg(n), dis(n), vis(n);
    deg.assign(n, 0), dis.assign(n, 0);
    for (ll i = 0; i < n; ++i) {
        deg[i] = G[i].size();
        dis[i] = INF;
        vis[i] = 0;
    }
    ll s = 0, t = n - 1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
    dis[t] = 0;
    Q.emplace(dis[t], t);
    while (!Q.empty()) {
        auto [d, u] = Q.top();
        Q.pop();
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        for (auto v : Gr[u]) {
            deg[v]--;
            auto w = deg[v] + dis[u] + 1;
            /**
             * @brief
             * Why distance is deg[v] + dis[u] + 1 ? dis[u] + 1 is easy:
             * distance to u, and need one more operation from u to v. But how
             * is deg[v]? Because if we want it from v to u, think about the
             * worst case: it may go other points. so we need deg[v] - 1
             * operation to BLOCK road to other points.
             * Another question is about why is deg[v]-- ? Because AFTER
             * considering this point, when v is visted again (i.e., from v to
             * point x), the basic operation needed must be not less then this
             * time (from v to u, then to n). So when considering such road, we
             * DON'T need to cut v - u because road to u costs less operation
             * then road to x when considering WORST case.
             */
            if (w < dis[v]) {
                dis[v] = w;
                Q.emplace(dis[v], v);
            }
        }
    }
    cout << dis[s] << "\n";
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