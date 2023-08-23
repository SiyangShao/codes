#include <atcoder/all>
#include <atcoder/modint.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
array<array<mint, 61>, 61> dp;
auto bit(auto m) {
    ll cnt = 0;
    while (m) {
        m /= 2;
        cnt++;
    }
    return cnt;
}
auto solve() {
    ll n, m;
    cin >> n >> m;
    if (bit(m) < n) {
        cout << "0\n";
        return;
    }
    dp[0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 61; ++j) {
            for (ll k = j + 1; k < 61; ++k) {
                ll l = (1LL << (k - 1));
                ll r = (1LL << k) - 1;
                r = min(r, m);
                if (l <= r) {
                    mint num = r - l + 1;
                    dp[i + 1][k] = dp[i][j] * num + dp[i + 1][k];
                } else {
                    break;
                }
            }
        }
    }
    mint ans = 0;
    for (ll i = 0; i < 61; ++i) {
        ans += dp[n][i];
    }
    cout << ans.val() << "\n";
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