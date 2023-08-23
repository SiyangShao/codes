#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD1 = 1000000007, MOD2 = 998244353;
constexpr ll N = 500000;
array<ll, N> fa, pow1, pow2, sz1, sz2;
ll d, n;
auto init() {
    srand(time(nullptr));
    for (int i = 0; i < N; ++i) {
        pow1[i] = 1LL * rand() * rand() % MOD1;
        pow2[i] = 1LL * rand() * rand() % MOD2;
    }
}
auto find(auto x) -> ll {
    if (fa[x] == x)
        return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
auto solve() {
    cin >> d >> n;
    unordered_map<ll, ll> mp;
    for (ll round = 1; round <= d; ++round) {
        for (ll i = 1; i <= n; ++i) {
            fa[i] = i;
            sz1[i] = pow1[i];
            sz2[i] = pow2[i];
        }
        vector<pair<ll, pair<ll, ll>>> e, v1, v2;
        for (ll i = 1, u, v, w; i < n; ++i) {
            cin >> u >> v >> w;
            e.push_back({w, {u, v}});
        }
        sort(e.begin(), e.end(),
             [](auto &a, auto &b) { return a.first > b.first; });

        for (auto i : e) {
            auto w = i.first, u = i.second.first, v = i.second.second;
            // cout << u << " " << v << "\n";
            u = find(u), v = find(v);
            if (u == v)
                continue;
            fa[u] = v;
            v1.push_back({w, {sz1[u], sz1[v]}});
            v2.push_back({w, {sz2[u], sz2[v]}});
            sz1[v] = (sz1[u] + sz1[v]) % MOD1;
            sz2[v] = (sz2[u] + sz2[v]) % MOD2;
        }
        ll s1 = 0, s2 = 0;
        for (ll i = 0; i < v1.size(); ++i) {
            s1 = (s1 + (v1[i].first *
                        ((v1[i].second.first * v1[i].second.second) % MOD1)) %
                           MOD1) %
                 MOD1;
            s2 = (s2 + (v2[i].first *
                        ((v2[i].second.first * v2[i].second.second) % MOD2)) %
                           MOD2) %
                 MOD2;
        }
        if (mp.find(s1 * MOD2 + s2 * MOD1) == mp.end()) {
            mp[s1 * MOD2 + s2 * MOD1] = round;
        }
        cout << mp[s1 * MOD2 + s2 * MOD1] << " ";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    solve();
}