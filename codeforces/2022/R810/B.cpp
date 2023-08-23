#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), deg(n, 0);
    for (auto &i : a) {
        cin >> i;
    }
    vector<pair<ll, ll>> edg(m);
    vector<vector<ll>> E(n);
    for (auto &[u, v] : edg) {
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }
    if (m % 2 == 0) {
        cout << "0\n";
        return;
    }
    // del only 1
    ll ans = accumulate(a.begin(), a.end(), 0);
    ll bs = ans;
    for (int i = 0; i < n; ++i) {
        if (deg[i] % 2 == 1) {
            ans = min(ans, a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] % 2 == 0) {
            ll tmp = bs;
            for (auto v : E[i]) {
                if (deg[v] % 2 == 0) {
                    tmp = min(tmp, a[i] + a[v]);
                }
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    auto _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}