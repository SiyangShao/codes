#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto cal(ll i, ll nxt, string &s) {
    ll l = s[i] - '0', r = s[i + 1] - '0';
    return (l ^ nxt) + (r ^ nxt);
}
auto solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<ll, 2>> dp(n), seg(n);
    dp.assign(n, {0, 0});
    seg.assign(n, {0, 0});
    seg[0][0] = 1;
    seg[0][1] = 1;
    dp[0][0] = cal(0, 0, s);
    dp[0][1] = cal(0, 1, s);
    for (int i = 2; i < n; i += 2) {
        auto L = dp[i - 2][0] + cal(i, 0, s), R = dp[i - 2][1] + cal(i, 0, s);
        dp[i][0] = min(L, R);
        if (L <= R) {
            seg[i][0] = seg[i - 2][0];
        } else {
            seg[i][0] = seg[i - 2][1] + 1;
        }
        L = dp[i - 2][0] + cal(i, 1, s), R = dp[i - 2][1] + cal(i, 1, s);
        dp[i][1] = min(L, R);
        if (R <= L) {
            seg[i][1] = seg[i - 2][1];
        } else {
            seg[i][1] = seg[i - 2][0] + 1;
        }
    }
    if (dp[n - 2][0] == dp[n - 2][1]) {
        cout << dp[n - 2][0] << " " << min(seg[n - 2][0], seg[n - 2][1])
             << "\n";
    } else if (dp[n - 2][0] < dp[n - 2][1]) {
        cout << dp[n - 2][0] << " " << seg[n - 2][0] << "\n";
    } else {
        cout << dp[n - 2][1] << " " << seg[n - 2][1] << "\n";
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