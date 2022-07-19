#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 7;
constexpr ll M = 500;
array<ll, N> x, y, t, a, reg;
array<array<ll, M>, M> blk;
ll n, m;
auto solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    ll siz_dif = min(ll(sqrt(m)) + 1LL, M);

    auto getupd = [&](ll t) {
        ll res = 0;
        for (ll i = 2; i <= siz_dif; ++i) {
            res += blk[i][t % i];
        }
        return res;
    };
    auto upd = [&](ll t, ll k, ll op) {
        ll bl = x[k] + y[k];
        auto row = blk[bl].begin();
        ll l = (t + x[k]) % bl, r = (t - 1) % bl;
        if (l <= r) {
            for (ll i = l; i <= r; ++i) {
                *(row + i) += op;
            }
        } else {
            for (ll i = 0; i <= r; ++i) {
                *(row + i) += op;
            }
            for (ll i = l; i < bl; ++i) {
                *(row + i) += op;
            }
        }
    };
    for (ll t = 1, op, k; t <= m; ++t) {
        cin >> op >> k;
        if (op == 1) {
            reg[k] = t;
            if (x[k] + y[k] > siz_dif) {
                for (ll j = t + x[k]; j <= m; j += x[k] + y[k]) {
                    a[j]++;
                    if (j + y[k] <= m) {
                        a[j + y[k]]--;
                    }
                }
            } else {
                upd(t, k, 1);
            }
        } else {
            if (x[k] + y[k] >= siz_dif) {
                for (int j = reg[k] + x[k]; j <= m; j += x[k] + y[k]) {
                    a[j]--;
                    if (j + y[k] <= m)
                        a[j + y[k]]++;
                    if (j < t && j + y[k] >= t)
                        ans--;
                }
            } else {
                upd(reg[k], k, -1);
            }
        }
        ans += a[t];
        cout << ans + getupd(t) << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}