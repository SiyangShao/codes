#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), dp(n + 1);
    a.assign(n + 1, 0), dp.assign(n + 1, 0);
    for (ll i = n; i >= 1; --i) {
        cin >> a[i];
    }
    dp[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        dp[i] = 0;
        for (ll jump = max(k, i - 1); jump >= 1; --jump) {
            dp[jump] = min(dp[jump] + a[i], dp[jump - 1] + (i - jump));
        }
        dp[0] += a[i];
    }
    cout << dp[k] << "\n";
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