#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e16 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), t(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : t) {
        cin >> i;
        if (i == 3) {
            i = 1;
        } else {
            i = 0;
        }
    }
    vector<vector<ll>> E(n);
    for (ll i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<ll> f(n), g(n);
    // f[i]: contribution of the subtree of i
    // g[i]: go i, and disturb i's son.
    // intially, g[i] = f[son] - a[son]
    // f[i] = max(f[i], g[i] + a[son])
    // t[son_a] == 3 case:
    // go son_b and back go son_a and do op on son_a's child
    // f[i] = max(f[i], g[i] + a[son_a] + g[son_b] + a[son_b] - f)
    function<void(ll, ll)> dfs = [&](ll u, ll fa) {
        ll mx1 = -INF, mx2 = -INF;
        g[u] = a[u];
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            dfs(v, u);
            g[u] += f[v] - a[v];
            auto tmp = g[v] + a[v] - f[v];
            if (tmp >= mx1) {
                mx2 = mx1;
                mx1 = tmp;
            } else if (tmp >= mx2) {
                mx2 = tmp;
            }
        }
        f[u] = g[u];
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            f[u] = max(f[u], g[u] + a[v]);
            if (t[v]) {
                if (g[v] + a[v] - f[v] == mx1) {
                    f[u] = max(f[u], g[u] + a[v] + mx2);
                } else {
                    f[u] = max(f[u], g[u] + a[v] + mx1);
                }
            }
        }
    };
    dfs(0, -1);
    cout << f[0] << "\n";
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