#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    vector<vector<ll>> E(n);
    E.assign(n, vector<ll>());
    map<pair<ll, ll>, ll> mp;
    mp.clear();
    for (ll i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v), E[v].emplace_back(u);
        mp[{u, v}] = i, mp[{v, u}] = i;
    }
    vector<ll> vis(n);
    vis.assign(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (~vis[i]) {
            continue;
        }
        vector<ll> tmp;
        tmp.clear();
        ll k = 0;
        for (ll j = i; vis[j] == -1; j = a[j]) {
            vis[j] = k++;
            tmp.emplace_back(j);
        }
        for (auto x : tmp) {
            sort(E[x].begin(), E[x].end(), [&](ll i, ll j) {
                return (vis[i] - vis[x] + k) % k < (vis[j] - vis[x] + k) % k;
            });
        }
    }
    vector<ll> cur(n);
    cur.assign(n, 0);
    auto dfs = [&](auto self, auto u) -> void {
        while (cur[u] < E[u].size()) {
            auto v = E[u][cur[u]];
            if (E[v][cur[v]] == u) {
                cout << mp[{u, v}] << " ";
                cur[v]++;
                cur[u]++;
            } else {
                self(self, v);
            }
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (cur[i] != E[i].size()) {
            dfs(dfs, i);
        }
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