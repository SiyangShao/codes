#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(n + 1, 0), ans(n + 1, 0);
    dp[0] = 1;
    ll pre = 0;
    for (int i = 1; i <= n; ++i) {
        ll stp = i + k - 1;
        pre += stp;
        for (int j = n; j >= stp; --j) {
            dp[j] = dp[j - stp];
        }
        for (int j = 0; j < stp; ++j) {
            dp[j] = 0;
        }
        for (int j = stp; j <= n; ++j) {
            dp[j] += dp[j - stp];
            dp[j] %= MOD;
        }
        for (int j = stp; j <= n; ++j) {
            ans[j] += dp[j];
            ans[j] %= MOD;
        }
        if (pre > 2 * n) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}