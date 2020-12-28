#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 5 + (1 << 18);
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, l, t;
array<vector<pair<ll, ll>>, N> E;
array<ll, N> x, ans, bits, dis, vis;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
auto merge(ll a, ll b) {
    if (a == 0)
        return b + 1;
    if ((a - 1) % l < b) {
        return a + b - (a - 1) % l;
    }
    return a + b - (a - 1) % l + l;
}
auto dij() {
    vis.fill(0);
    while (!Q.empty()) {
        auto [d, u] = Q.top();
        Q.pop();
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        for (auto [b, v] : E[u]) {
            if (dis[v] > merge(dis[u], b)) {
                dis[v] = merge(dis[u], b);
                Q.emplace(dis[v], v);
            }
        }
    }
}
auto solve() {
    cin >> n >> l >> t;
    for (ll i = 0, u, v; i < l; ++i) {
        cin >> u >> v;
        E[v].emplace_back(i, u);
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
        ans[i] = 0;
    }
    for (ll k = 1; k <= 256; k *= 2) {
        for (int i = 1; i <= n; ++i) {
            if (x[i] & k) {
                bits[i] = 1;
                dis[i] = 0;
                Q.emplace(dis[i], i);
            } else {
                dis[i] = INF;
                bits[i] = 0;
            }
            // cout<<bits[i]<<" ";
        }
        // cout<<"\n";
        dij();
        for (int i = 1; i <= n; ++i) {
            if (dis[i] <= t) {
                ans[i] += k;
            }
            // cout<<dis[i]<<" ";
        }
        // cout<<"\n";
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    while (_--) {
        solve();
    }
}