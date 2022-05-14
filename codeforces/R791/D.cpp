#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), vis(n + 1), val(n + 1), res(n + 1);
    vis.assign(n + 1, 0);
    res.assign(n + 1, k);
    vector<vector<ll>> E;
    E.assign(n + 1, vector<ll>());
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        val[i] = a[i];
        E[0].emplace_back(i);
    }
    for (ll i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        E[u].emplace_back(v);
    }
    auto cmp = [&](auto i, auto j) { return a[i] < a[j]; };
    for (int i = 0; i <= n; ++i) {
        if (!E[i].empty())
            sort(E[i].begin(), E[i].end(), cmp);
    }
    ll ans = *max_element(a.begin(), a.end()) + 1;
    ll tmp = ans;
    auto dfs = [&](auto self, auto u) -> void {
        if (res[u] == 0) {
            ans = min(ans, val[u]);
            return;
        }
        for (auto v : E[u]) {
            if (res[v] - n > res[u] - 1) {
                ans = min(ans, val[v]);
                return;
            }
            res[v] = min(res[v], res[u] - 1);
            if (res[v] == res[u] - 1) {
                val[v] = max(val[v], val[u]);
                self(self, v);
            }
        }
    };
    dfs(dfs, 0);
    if (tmp == ans) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
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