#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> E(n);
    vector<ll> siz, ans;
    E.assign(n, vector<ll>());
    siz.assign(n, 1);
    ans.assign(n, 0);
    for (ll i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    auto dfs = [&](auto self, auto u, auto fa) -> void {
        ll tmp = 0;
        for (auto v : E[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
            tmp += siz[v] * siz[v];
        }
        ans[u] = ((siz[u] - 1) * (siz[u] - 1) - tmp) / 2 +
                 siz[u] * (n - siz[u]) + siz[u] - 1;
    };
    ll q;
    cin >> q;
    dfs(dfs, 0, -1);
    while (q--) {
        ll x;
        cin >> x;
        x--;
        cout << ans[x] << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}