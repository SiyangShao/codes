#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 4e4 + 7;
vector<ll> p;
array<array<ll, 500>, N> dp;
// dp[i][j] means i represented by numbers not larger then p[j]
bool is_palindromic(ll x) {
    ll i = x, y = 0;
    while (i) {
        y = y * 10 + i % 10;
        i /= 10;
    }
    return x == y;
}
auto init() {
    for (int i = 1; i < N; ++i) {
        if (is_palindromic(i)) {
            dp[i][p.size()] = 1;
            p.emplace_back(i);
        }
    }
    for (int i = 1; i < N; ++i) {
        dp[i][0] = 1;
    }
    for (int k = 1; k < p.size(); ++k) {
        for (int i = 1; i < N; ++i) {
            dp[i][k] = (dp[i][k] + dp[i][k - 1]) % MOD;
            if (i + p[k] < N)
                dp[i + p[k]][k] = (dp[i + p[k]][k] + dp[i][k]) % MOD;
        }
    }
}
auto solve() {
    ll n;
    cin >> n;
    cout << dp[n][498] << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}