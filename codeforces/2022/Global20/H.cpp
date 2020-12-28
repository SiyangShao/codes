#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "_" + s;
    vector<array<ll, 2>> dp(n + 1);
    dp.assign(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if (s[i] == s[i - 1]) {
            dp[i][s[i] - '0']++;
        }
        // dp[i][0]: number to split 0
        // dp[i][1]: number to split 1
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << max(dp[r][0] - dp[l][0], dp[r][1] - dp[l][1]) + 1 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}