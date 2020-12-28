#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> E(n);
    vector<ll> siz(n), dp(n);
    siz.assign(n, 1), dp.assign(n, 0);
    E.assign(n, vector<ll>());
    for (ll i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    auto dfs = [&](auto self, auto u, auto fa) -> void {
        ll ans = 0;
        for (auto v : E[u]) {
            if (v != fa) {
                self(self, v, u);
                siz[u] += siz[v];
                ans += dp[v];
            }
        }
        for (auto v : E[u]) {
            if (v != fa) {
                dp[u] = max(dp[u], ans - dp[v] + siz[v] - 1);
            }
        }
    };
    dfs(dfs, 0, -1);
    cout << dp[0] << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}