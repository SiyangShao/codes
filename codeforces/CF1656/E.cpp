#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> E(n);
    for (ll i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<ll> ans(n);
    auto dfs = [&](auto self, auto u, auto fa, auto x) -> void {
        ans[u] = x;
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            self(self, v, u, x == 0 ? 1 : -x);
            ans[u] -= x == 0 ? 1LL : -x;
        }
    };
    dfs(dfs, 0, -1, 0);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
}