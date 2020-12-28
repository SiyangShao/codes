#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 1010;
array<ll, N> fact, inv_fact;
array<unordered_map<ll, ll>, 64> mp;
ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}
auto init() {
    for (int i = 0; i < 64; ++i) {
        mp[i].clear();
    }
    fact[0] = 1;
    for (ll i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[N - 1] = qpow(fact[N - 1], MOD - 2) % MOD;
    for (ll i = N - 2; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}
auto C(ll n, ll m) {
    return ((fact[n] * inv_fact[n - m] % MOD) * inv_fact[m]) % MOD;
}
ll n, l, r, z;
auto dfs(ll bit, ll rest) -> ll {
    // now searching bit-th bit, sum should not larger then rest
    if (bit < 0)
        return 1;
    if (rest < 0)
        return 0;
    if (mp[bit].contains(rest)) {
        return mp[bit][rest];
    }
    if ((1LL << (bit + 1)) - 1 <= rest / n) {
        // all rest cases are ok
        // leave 1 col to suit z
        // totally (n-1) * (bit+1) points, could be either 0 or 1
        return mp[bit][rest] = qpow(2, (n - 1) * (bit + 1));
    }
    ll ans = 0, bs = (1LL) << bit;
    for (ll i = ((z >> bit) & 1); i <= n && i * bs <= rest; i += 2) {
        // can choose i bits to be 1, rest is 0
        ans = (ans + (C(n, i) * dfs(bit - 1, rest - i * bs)) % MOD) % MOD;
    }
    return mp[bit][rest] = ans;
}
auto solve() {
    cin >> n >> l >> r >> z;
    ll R = dfs(60, r);
    ll L = dfs(60, l - 1);
    if (R < L) {
        R += MOD;
    }
    cout << (R - L) % MOD << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    init();
    // cin >> _;
    while (_--) {
        solve();
    }
}