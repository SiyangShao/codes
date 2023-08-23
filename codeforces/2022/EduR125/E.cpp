#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k + 1, vector<ll>(n, 0));
    vector<vector<ll>> C(n);
    for (ll i = 0; i < n; ++i) {
        C[i].assign(i + 1, 0);
        C[i][0] = C[i][i] = 1;
        for (ll j = 1; j < i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    dp[0][0] = 1;
    for (ll i = 0; i < k; ++i) {
        for (ll t = 0; t < n; ++t) {
            auto pw = qpow(k - i, t * (t - 1) / 2);
            auto stp = qpow(k - i, t);
            for (ll j = 0; j < n - t; ++j) {
                dp[i + 1][j + t] =
                    (dp[i + 1][j + t] +
                     (dp[i][j] * (C[n - 1 - j][t] * pw % MOD)) % MOD) %
                    MOD;
                pw = pw * stp % MOD;
            }
        }
    }
    cout << dp[k][n - 1];
}