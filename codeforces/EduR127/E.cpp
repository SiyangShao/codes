#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll MMOD = 1000000007;
auto solve() {
    ll n;
    cin >> n;
    n = 1 << n;
    n--;
    string s;
    cin >> s;
    vector<ll> mp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'A') {
            mp[i] = 1;
        } else {
            mp[i] = 0;
        }
    }
    vector<ll> dp(n + 1), level(n + 1);
    vector<pair<ll, ll>> hash(n + 1);
    dp.assign(n + 1, 0);
    hash.assign(n + 1, {0, 0});
    level.assign(n + 1, 0);
    auto dfs = [&](auto self, auto i) {
        if (i * 2 > n) {
            dp[i] = 1;
            level[i] = 1;
            return hash[i] = {mp[i], mp[i]};
        }
        auto lson = self(self, i * 2);
        auto rson = self(self, i * 2 + 1);
        level[i] = level[i * 2] + level[i * 2 + 1] + 1;
        if (lson == rson) {
            dp[i] = dp[i * 2] * dp[i * 2 + 1] % MOD;
            ll res = (1 << (level[i] - 1)) * mp[i] +
                     lson.first * (1 << level[i * 2 + 1]) + rson.first;
            res %= MOD;
            ll tmp = (1 << (level[i] - 1)) * mp[i] +
                     lson.second * (1 << level[i * 2 + 1]) + rson.second;
            tmp %= MMOD;
            return hash[i] = {res, tmp};
        } else {
            dp[i] = 2 * dp[i * 2 + 1] * dp[i * 2] % MOD;
            if (lson.first > rson.first) {
                swap(lson, rson);
            }
            ll res = (1 << (level[i] - 1)) * mp[i] +
                     lson.first * (1 << level[i * 2 + 1]) + rson.first;
            res %= MOD;
            ll tmp = (1 << (level[i] - 1)) * mp[i] +
                     lson.second * (1 << level[i * 2 + 1]) + rson.second;
            tmp %= MMOD;
            return hash[i] = {res, tmp};
        }
    };
    dfs(dfs, 1);
    cout << dp[1] << "\n";
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