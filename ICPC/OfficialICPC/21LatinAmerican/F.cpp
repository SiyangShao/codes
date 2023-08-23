#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<vector<ll>> E;
class DSU {
  public:
    vector<ll> fa, siz;
    ll n;
    DSU(ll _n) : n(_n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        siz.assign(n, 1);
    }
    auto find(ll u) {
        if (u == fa[u])
            return u;
        return fa[u] = find(fa[u]);
    }
    auto merge(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (siz[u] > siz[v])
            swap(u, v);
        fa[u] = v;
        siz[v] += siz[u];
        return true;
    }
};
auto solve() {
    cin >> n >> m;
    E.assign(n, vector<ll>());
    DSU dsu(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<ll> vis;
    vis.assign(n, 0);
    auto dfs = [&](auto self, auto u) {
        if (u == n - 1 || vis[u]) {
            return;
        }
        vis[u] = 1;
        for (auto v : E[u]) {
            if (!vis[v] && v != n - 1) {
                dsu.merge(v, n - 2);
                self(self, v);
            }
        }
    };
    dfs(dfs, n - 2);
    for (ll i = 0; i < n; ++i) {
        if (dsu.find(i) == dsu.find(n - 2)) {
            cout << "B";
        } else {
            cout << "A";
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