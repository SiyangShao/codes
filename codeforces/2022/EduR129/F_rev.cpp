#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, ans;
vector<vector<pair<ll, ll>>> E;
vector<vector<ll>> g;
vector<ll> siz, f, root;
// Same method as F.cpp
auto dfs(ll u, ll fa) -> void {
    for (auto &[v, w] : E[u]) {
        if (v == fa) {
            continue;
        }
        g[w].emplace_back(v);
        dfs(v, u);
        siz[u] += siz[v];
        g[w].pop_back();
        if (g[w].empty()) {
            root[w] -= siz[v];
        } else {
            f[g[w].back()] -= siz[v];
        }
    }
    f[u] += siz[u];
}
auto dp(ll u, ll fa) -> void {
    for (auto &[v, w] : E[u]) {
        if (v == fa) {
            continue;
        }
        if (g[w].empty()) {
            ans += f[v] * root[w];
            // Case 2, from root to w doesn't exit path with value w
        } else {
            ans += f[v] * f[g[w].back()];
            // Case 1, number of last * number of this
        }
        g[w].emplace_back(v);
        dp(v, u);
        g[w].pop_back();
    }
}
auto solve() {
    cin >> n;
    E.assign(n, vector<pair<ll, ll>>());
    g.assign(n, vector<ll>());
    siz.assign(n, 1), f.assign(n, 0), root.assign(n, n);
    for (ll i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        u--, v--, w--;
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
    }
    dfs(0, -1);
    ans = 0;
    dp(0, -1);
    cout << ans << "\n";
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