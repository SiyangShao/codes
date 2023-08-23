#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<vector<ll>>> E(n);
    for (ll i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        E[u].push_back({v, w, i});
        E[v].push_back({u, w, i});
    }
    vector<ll> dis(n), idx(n);
    dis.assign(n, 1LL << 60);
    dis[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
    Q.emplace(0, 0);
    while (!Q.empty()) {
        auto [d, u] = Q.top();
        Q.pop();
        if (d != dis[u]) {
            continue;
        }
        for (auto e : E[u]) {
            auto v = e[0], w = e[1], id = e[2];
            if (dis[v] > d + w) {
                dis[v] = d + w;
                idx[v] = id;
                Q.emplace(dis[v], v);
            }
        }
    }
    for (ll i = 1; i < n; ++i) {
        cout << idx[i] << " \n"[i == n - 1];
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