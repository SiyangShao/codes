#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, ans;
vector<vector<pair<ll, ll>>> E;
vector<vector<ll>> g;
vector<ll> siz, f;
/**
 * @brief
 * Build f. when x < n (real node), f[x] means number of nodes connected with x
 * but the path between them doesn't contain same value as the path between x
 * and x's parent. When x>=n, f[x] means number of nodes connected with the root
 * that the path doesn't contain value (x-n).
 * @param u
 * @param fa
 */
auto dfs(ll u, ll fa) -> void {
    siz[u] = 1;
    for (auto &[v, w] : E[u]) {
        if (v == fa) {
            continue;
        }
        g[w].emplace_back(v);
        // cout << "Road of " << w << ": ";
        // for (auto &i : g[w]) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        dfs(v, u);
        siz[u] += siz[v];
        g[w].pop_back();
        f[g[w].back()] -= siz[v];
    }
    f[u] += siz[u];
}
/**
 * @brief
 * Think about the path from u to v, with value w. The contribution of this path
 * equals to the (number of nodes connected with u but witouht value w) multiply
 * (number of nodes connected with v but without value w). Case 1: From root to
 * u, there HAS path with value w. Suppose that node is p (the edge between p
 * and fa[p] is value w). Than as we defined before, contribution for path u-v
 * is f[p] * f[v]. Case 2: There doesn't exist such a node p. Then it's the
 * number of nodes connected with root without value w (f[w + n], as we defined
 * before) * f[v].
 * @param u
 * @param fa
 */
auto dp(ll u, ll fa) -> void {
    for (auto &[v, w] : E[u]) {
        if (v == fa) {
            continue;
        }
        ans += f[v] * f[g[w].back()];
        // cout << "From " << u << " to " << v << ": " << w << " " <<
        // g[w].back()
        //      << " " << f[v] << " " << f[g[w].back()] << "\n";
        g[w].emplace_back(v);
        dp(v, u);
        g[w].pop_back();
    }
}
auto solve() {
    cin >> n;
    E.assign(n, vector<pair<ll, ll>>());
    g.assign(n, vector<ll>());
    siz.assign(n, 0), f.assign(n + n, 0);
    for (ll i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        u--, v--, w--;
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
    }
    for (ll i = 0; i < n; ++i) {
        g[i].emplace_back(n + i);
        f[i + n] = n;
    }
    dfs(0, -1);
    ans = 0;
    // for (auto &i : f) {
    //     cout << i << " ";
    // }
    // cout << "\n";
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