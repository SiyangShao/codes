#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll N = 1010;
constexpr ll S = 18;
array<array<ll, N>, N> d, p;
array<array<ll, S>, 1 << S> dp;
auto qpow(auto x, auto y) {
    auto res = 1LL;
    while (y) {
        if (y & 1) {
            res = res * x % MOD;
        }
        y >>= 1;
        x = x * x % MOD;
    }
    return res;
}
auto solve() {
    ll n, q;
    string s;
    cin >> n >> s >> q;
    ll num = 0;
    for (auto i : s) {
        num += i == '?';
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            p[i][j] = num;
        }
    }
    for (ll len = 1; len <= n; ++len) {
        for (ll i = 0; i + len <= n; ++i) {
            auto j = i + len - 1;
            auto &curd = d[i][j], &curp = p[i][j];
            if (i == j) {
                curp = num;
            } else {
                auto cnt = (s[i] == '?') + (s[j] == '?');
                if (s[i] != s[j] && cnt == 0) {
                    curp = -1;
                    continue;
                }
                curd = d[i + 1][j - 1];
                curp = p[i + 1][j - 1] - 1;
                if (cnt == 0)
                    curp++;
                if (curp < 0)
                    continue;
                if (cnt == 1) {
                    auto ch = (s[i] == '?') ? s[j] : s[i];
                    curd |= (1 << (ch - 'a'));
                }
            }
            if (curp < 0)
                continue;
            for (ll k = 1; k < S; ++k) {
                dp[curd][k] = (dp[curd][k] + qpow(k, curp)) % MOD;
            }
        }
    }
    for (ll i = 0; i < S; ++i) {
        for (ll j = 0; j < (1 << S); ++j) {
            if ((1 << i) & j) {
                for (ll k = 1; k < S; ++k) {
                    dp[j][k] = (dp[j][k] + dp[(1 << i) ^ j][k]) % MOD;
                }
            }
        }
    }
    while (q--) {
        cin >> s;
        auto t = 0LL;
        for (auto i : s) {
            t |= (1 << (i - 'a'));
        }
        cout<<dp[t][s.length()]<<"\n";
    }
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