#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 1e5 + 7;
array<ll, N> frac, inv_frac;
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
auto init() {
    frac[0] = 1;
    for (ll i = 1; i < N; ++i) {
        frac[i] = frac[i - 1] * i % MOD;
    }
    inv_frac[N - 1] = qpow(frac[N - 1], MOD - 2);
    for (ll i = N - 1; i > 0; --i) {
        inv_frac[i - 1] = inv_frac[i] * i % MOD;
    }
}
auto P(ll n, ll m) {
    assert(n >= m);
    // cout << "P " << n << " " << m << "\n";
    return frac[n] * inv_frac[n - m] % MOD;
}
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> vis(n + 1);
    vis[n] = 0;
    for (auto &i : a) {
        cin >> i;
    }
    map<ll, ll> mp;
    mp.clear();
    for (ll i = 0; i < n; ++i) {
        mp[a[i]] = i;
        vis[i] = 0;
    }
    vis[0] = 1;
    ll L = mp[0], R = mp[0];
    ll not_mex = 0, res = 1, mex = 1;
    auto add_range = [&](auto l, auto r) {
        for (ll i = l; i <= r; ++i) {
            vis[a[i]] = 1;
        }
        ll add = 0, all = 0;
        while (vis[mex]) {
            add++;
            mex++;
        }
        assert(add >= 1);
        add--;
        for (ll i = l + 1; i < r; ++i) {
            all++;
        }
        not_mex += all;
        res = res * P(not_mex, add) % MOD;
        not_mex -= add;
    };
    for (ll i = 1; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        // cout<<L<<" "<<R<<" "<<i<<"\n";
        if (mp[i] < L) {
            add_range(mp[i], L);
            L = mp[i];
        } else {
            add_range(R, mp[i]);
            R = mp[i];
        }
    }
    res = res * P(not_mex, not_mex) % MOD;
    cout << res << "\n";
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