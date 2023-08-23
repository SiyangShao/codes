#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, m, k, s, t;
vector<ll> dis, vis;
vector<vector<pair<ll, ll>>> E;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
auto solve() {
    cin >> n >> m >> k;
    cin >> s >> t;
    dis.assign(n * (k + 1), INF);
    vis.assign(n * (k + 1), 0);
    E.assign(n * (k + 1), vector<pair<ll, ll>>());
    for (ll i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        E[u].emplace_back(v, w);
        for (ll j = 1; j <= k; ++j) {
            E[u + j * n].emplace_back(v + j * n, w);
            E[u + (j - 1) * n].emplace_back(v + j * n, 0);
        }
        E[v].emplace_back(u, w);
        for (ll j = 1; j <= k; ++j) {
            E[v + j * n].emplace_back(u + j * n, w);
            E[v + (j - 1) * n].emplace_back(u + j * n, 0);
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < k; ++j) {
            E[i + j * n].emplace_back(i + (j + 1) * n, 0);
        }
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
    cout << dis[t + n * k] << "\n";
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