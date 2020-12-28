#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(2));
    dp.assign(n, vector<pair<ll, ll>>(2, {0,LONG_LONG_MIN}));
    vector<vector<ll>> E;
    E.assign(n, vector<ll>());
    vector<ll> val(n);
    val.assign(n, 0);

    for (int i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v), E[v].emplace_back(u);
    }
    if (n == 2) {
        cout << "2 2\n1 1\n";
        return;
    }
    auto dfs1 = [&](auto self, ll u, ll fa) -> void {
        dp[u][1].first = 1;
        dp[u][1].second = -E[u].size();
        dp[u][0].second = -1;
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            self(self, v, u);
            dp[u][1].first += dp[v][0].first;
            dp[u][1].second += dp[v][0].second;
            ll best = dp[v][1] >= dp[v][0];
            dp[u][0].first += dp[v][best].first;
            dp[u][0].second += dp[v][best].second;
        }
    };
    dfs1(dfs1, 0, 0);
    ll best = dp[0][1] >= dp[0][0];
    auto dfs2 = [&](auto self, auto u, auto fa, auto b) -> void {
        val[u] = (b ? E[u].size() : 1);
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            if (b) {
                self(self, v, u, 0);
            } else {
                ll best = dp[v][1] >= dp[v][0];
                self(self, v, u, best);
            }
        }
    };
    dfs2(dfs2, 0, 0, best);
    cout << dp[0][best].first << " " << -dp[0][best].second << "\n";
    for (auto i : val) {
        cout << i << " ";
    }
    cout << "\n";
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