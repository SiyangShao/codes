#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), pan;
    pan.emplace_back(0);
    for (auto &i : a) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            pan.emplace_back(i);
            auto l = pan.rbegin(), r = pan.rbegin() + 1;
            *l += *r;
        }
        if (i > 0)
            a[i] += a[i - 1];
    }
    vector<vector<vector<ll>>> dp(
        n, vector<vector<ll>>(m + 1, vector<ll>(m + 1, INT_MAX)));
    for (ll j = 0; j <= m; ++j) {
        if (a[0] >= j) {
            dp[0][j][j] = a[0] - j;
        } else {
            dp[0][j][j] = pan[j];
        }
    }
    for (auto j = m - 1; j >= 0; --j) {
        for (auto k = j; k <= m; ++k) {
            dp[0][j][k] = min(dp[0][j][k], dp[0][j + 1][k]);
        }
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            for (ll k = j; k <= m; ++k) {
                auto add = 0LL;
                if (a[i] >= k) {
                    add = a[i] - k;
                } else {
                    auto lend = min(j, k - a[i]);
                    add = pan[k] - pan[k - lend] - i * lend;
                }
                dp[i][j][k] = dp[i - 1][j][k - j] + add;
            }
        }
        for (ll j = m - 1; j >= 0; --j) {
            for (ll k = (i + 1) * j; k <= m; ++k) {
                dp[i][j][k] = min(dp[i][j][k], dp[i][j + 1][k]);
            }
        }
    }
    cout << dp[n - 1][0][m] << "\n";
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