#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (auto &i : h) {
        cin >> i;
    }
    if (n % 2 == 1) {
        ll ans = 0;
        for (ll i = 1; i < n; i += 2) {
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                continue;
            }
            ans += max(h[i - 1], h[i + 1]) + 1 - h[i];
        }
        cout << ans << "\n";
    } else {
        vector<ll> dp(n);
        ll ans = 0;
        for (ll i = 1; i < n - 1; i += 2) {
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                dp[i] = ans;
            } else {
                ans += max(h[i - 1], h[i + 1]) + 1 - h[i];
                dp[i] = ans;
            }
        }
        ans = 0;
        for (ll i = n - 2; i > 0; i -= 2) {
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                dp[i] = ans;
            } else {
                ans += max(h[i - 1], h[i + 1]) + 1 - h[i];
                dp[i] = ans;
            }
        }
        ans = dp[n - 3];
        for (ll i = 1; i < n - 1; i += 2) {
            ll cnt = 0;
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                cnt = 0;
            } else {
                cnt = max(h[i - 1], h[i + 1]) + 1 - h[i];
            }
            ans = min(ans, dp[i + 1] + dp[i] - cnt);
        }
        cout << ans << "\n";
    }
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