#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 5e5 + 7;
auto qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
array<ll, N> frac, inv_frac;
auto init() {
    frac[0] = 1;
    for (ll i = 1; i < N; ++i) {
        frac[i] = frac[i - 1] * i % MOD;
    }
    inv_frac[N - 1] = qpow(frac[N - 1], MOD - 2);
    for (ll i = N - 1; i > 0; --i) {
        inv_frac[i - 1] = inv_frac[i] * (i) % MOD;
    }
}
auto solve() {
    // \sum_{i=0}^{n} \sum_{j=0}^{a_i-1} C(i+j,i) = \sum_{i=0}^{n}(i+a_i,i+1)
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (auto &i : a) {
        cin >> i;
    }
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        if (a[i] == 0)
            break;
        ll res =
            (frac[i + a[i]] * inv_frac[i + 1]) % MOD * inv_frac[a[i] - 1] % MOD;
        ans = (ans + res) % MOD;
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
}