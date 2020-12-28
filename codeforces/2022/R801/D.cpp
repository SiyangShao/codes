#include <bits/stdc++.h>
#include <type_traits>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16 + 7;
auto solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vector<vector<ll>> E(n, vector<ll>());
    for (ll i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<ll> dp(n, 0), single(n, 0);
    function<void(ll, ll)> dfs = [&](auto u, auto fa) {
        dp[u] = 0;
        bool flag = false;
        for (auto v : E[u]) {
            if (v == fa) {
                continue;
            }
            dfs(v, u);
            if (dp[v] == 0) {
                single[u]++;
            } else {
                dp[u] += dp[v];
            }
        }
        if (single[u] > 1) {
            dp[u] += single[u] - 1;
        }
    };
    dfs(0, -1);
    ll ans = n;
    function<void(ll, ll)> root = [&](auto u, auto fa) {
        ans = min(ans, dp[u] + 1);
        for (auto v : E[u]) {
            if (v == fa) {
                continue;
            }
            ll U = dp[u], V = dp[v], SU = single[u], SV = single[v];
            // OPERATION
            dp[u] -= max(0LL, single[u] - 1) + dp[v];
            if (dp[v] == 0) {
                single[u]--;
            }
            dp[u] += max(0LL, single[u] - 1);
            dp[v] -= max(0LL, single[v] - 1);
            if (dp[u] == 0) {
                single[v]++;
            }
            dp[v] += max(0LL, single[v] - 1) + dp[u];
            root(v, u);
            dp[u] = U, dp[v] = V;
            single[u] = SU, single[v] = SV;
        }
    };
    root(0, -1);
    cout << ans << "\n";
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