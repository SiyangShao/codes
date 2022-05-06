#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    n = 1 << n;
    vector<vector<ll>> E(n);
    vector<ll> val(n);
    vector<pair<ll, ll>> edge(n - 1);
    map<pair<ll, ll>, ll> mp;
    iota(val.begin(), val.end(), 0);
    for (auto &[u, v] : edge) {
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    auto dfs = [&](auto self, auto u, auto fa, auto cnt) -> void {
        if (cnt % 2 == 0) {
            val[u] ^= n;
        }
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            self(self, v, u, cnt + 1);
            mp[{u, v}] = mp[{v, u}] = val[v] ^ n;
        }
    };
    dfs(dfs, 0, -1, 0);
    cout << 1 << "\n";
    for (auto i : val) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto e : edge) {
        cout << mp[e] << " ";
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}