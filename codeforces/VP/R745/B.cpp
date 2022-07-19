#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 105;
ll n, m, k, P;
array<ll, N> fac;
array<array<ll, N>, N> c;
array<array<array<ll, N>, N>, N> dp;
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k >> P;
    m--;
    for (ll i = c[0][0] = fac[0] = 1; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        fac[i] = 1ll * fac[i - 1] * i % P;
        for (ll j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
    }
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            for (ll k = 0; k < N; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    function<void(ll, ll, ll)> dfs = [&](ll sz, ll cnt, ll dep) {
        if (dp[dep][sz][cnt] != -1) {
            return;
        }
        auto F = &dp[dep][sz][cnt];
        *F = 0;
        if (!sz) {
            *F = 1;
            return;
        }
        if ((m - dep < 7 && (1 << (m - dep)) < cnt) || (cnt && sz < m - dep))
            return;
        if (dep == m) {
            *F = (cnt == 1 ? fac[sz] : 0);
            return;
        }
        for (ll i = 0; i < sz; ++i) {
            ll fi = 0;
            for (ll j = max(0LL, cnt + i + 1 - sz); j <= min(cnt, i); ++j) {
                if (dp[dep + 1][i][j] && dp[dep + 1][sz - i - 1][cnt - j]) {
                    dfs(i, j, dep + 1);
                    dfs(sz - i - 1, cnt - j, dep + 1);
                    fi = (fi + 1ll * dp[dep + 1][i][j] *
                                   dp[dep + 1][sz - i - 1][cnt - j]) %
                         P;
                }
            }
            *F = (*F + fi * c[sz - 1][i]) % P;
        }
    };

    dfs(n, k, 0);
    cout << dp[0][n][k] << "\n";
}