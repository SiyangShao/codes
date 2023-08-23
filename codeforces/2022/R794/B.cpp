#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (auto &i : p) {
        cin >> i;
        i--;
    }
    vector<ll> dp(n + 1);
    dp.assign(n + 1, 0);
    for (ll i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + (p[i - 2] > p[i - 1] ? 1 : 0));
    }
    cout << dp[n] << "\n";
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