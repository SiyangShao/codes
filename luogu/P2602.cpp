#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 15;
array<ll, N> dp, qpow, bit;
auto init() {
    qpow[0] = 1LL;
    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] * 10LL + qpow[i - 1];
        qpow[i] = qpow[i - 1] * 10LL;
    }
}
auto dfs(ll n, ll k) {
    // get from 1 to n, k appear times
    ll len = 0, res = n, ans = 0;
    while (n) {
        bit[++len] = n % 10;
        n /= 10;
    }
    for (auto i = len; i >= 1; --i) {
        ans += dp[i - 1] * bit[i];
        if (k < bit[i]) {
            ans += qpow[i - 1];
        }
        res -= qpow[i - 1] * bit[i];
        if (k == bit[i]) {
            ans += res + 1;
        }
        if (k == 0) {
            ans -= qpow[i - 1];
        }
    }
    return ans;
}
auto solve() {
    ll l, r;
    cin >> l >> r;
    for (int i = 0; i < 10; ++i) {
        cout << dfs(r, i) - dfs(l - 1, i) << " \n"[i == 9];
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}