#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll digit = 10;
constexpr ll siz = 1 << digit;
array<array<ll, digit>, digit> mp;
array<ll, siz> camp;
array<array<ll, digit>, siz> tran;
array<array<ll, siz>, 2> dp;
ll n, m;
// Suppose x is the representive (smallest) of the class
// there DOESN'T exist substring from a to b, that
// dig[a] > dig[b], there exists edge from a ~ b-1 to b
auto solve() {
    cin >> n >> m;
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        mp[u][v] = mp[v][u] = 1;
    }
    camp.fill(-1);
    for (ll mask = 0; mask < siz; ++mask) {
        for (ll j = 0; j < digit; ++j) {
            tran[mask][j] = 1 << j;
            if (mask & (1 << j))
                for (ll k = j + 1; k < digit; ++k) {
                    if (mp[j][k] && (camp[mask] & (1 << k))) {
                        camp[mask] ^= 1 << k;
                    }
                }
            for (ll k = 0; k < digit; ++k) {
                if ((mask & (1 << k)) && mp[j][k]) {
                    tran[mask][j] |= 1 << k;
                }
            }
        }
    }
    dp[0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        dp[(i + 1) % 2].fill(0);
        for (ll mask = 0; mask < siz; ++mask) {
            if (dp[i % 2][mask] == 0)
                continue;
            for (ll c = 0; c < digit; ++c) {
                if (camp[mask] & (1 << c)) {
                    dp[(i + 1) % 2][tran[mask][c]] =
                        (dp[(i + 1) % 2][tran[mask][c]] + dp[i % 2][mask]) %
                        MOD;
                }
            }
        }
    }
    auto ans = 0LL;
    for (ll mask = 0; mask < siz; ++mask) {
        ans = ans + dp[n % 2][mask];
        ans %= MOD;
    }
    cout << ans << "\n";
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