#include <algorithm>
#include <array>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> in, dp;
    vector<vector<ll>> E;
    in.assign(n, 0), E.assign(n, vector<ll>());
    dp.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        in[v]++;
    }
    auto dfs = [&](auto self, int u) {
        if (dp[u] > 0)
            return;
        dp[u] = 1;
        if (E[u].size() <= 1)
            return;
        for (auto v : E[u]) {
            self(self, v);
            if (in[v] >= 2) {
                dp[u] = max(dp[u], dp[v] + 1);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        dfs(dfs, i);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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