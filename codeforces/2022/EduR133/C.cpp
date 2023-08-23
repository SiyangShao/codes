#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll m;
    cin >> m;
    vector a(2, vector<ll>(m));
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    a[0][0] = -1;
    /**
     * @brief Observation: We can calculate the "earliest" time when we finish
     * the dp. It's hard to calculate how much time we cost on the road because
     * it depends on the time we start, and it's undefined while dp. But
     * earliest time is fixed. ASSUME: If we went out later than 0, the time
     * cost is max(cur + rest_blocks, dp).
     *
     */
    vector dp(2, vector<ll>(m + 1, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            dp[i][j] = max({a[i ^ 1][j] + 1, a[i][j] + 1 + 2 * (m - j) - 1,
                            dp[i][j + 1] + 1});
        }
    }
    ll ans = 1e16, cur = 0;
    for (int j = 0; j < m; ++j) {
        ll k = j & 1;
        ans = min(ans, max(cur + 2 * (m - j) - 1, dp[k][j]));
        cur = max(cur, a[k][j] + 1);
        cur++;
        cur = max(cur, a[k ^ 1][j] + 1);
        cur++;
    }
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