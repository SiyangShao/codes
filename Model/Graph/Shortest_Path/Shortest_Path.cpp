#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, m, s;
vector<ll> dis, vis;
vector<vector<pair<ll, ll>>> E;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
auto solve() {
    cin >> n >> m >> s;
    s--;
    dis.assign(n, INF);
    vis.assign(n, 0);
    E.assign(n, vector<pair<ll, ll>>());
    for (ll i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        E[u].emplace_back(v, w);
        // E[v].emplace_back(u, w);
    }
    dis[s] = 0;
    Q.emplace(0, s);
    while (!Q.empty()) {
        auto [d, u] = Q.top();
        Q.pop();
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        for (auto [v, w] : E[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.emplace(dis[v], v);
            }
        }
    }
    for (auto &i : dis) {
        cout << i << " ";
    }
    cout << "\n";
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