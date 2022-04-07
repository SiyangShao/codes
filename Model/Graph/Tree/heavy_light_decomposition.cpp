// 树链剖分
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 500010;
ll n, m, s, tot;
array<vector<ll>, N> E;
vector<ll> fa(N), dep(N), siz(N), son(N), top(N), dfn(N), rnk(N);
// E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
// top: top of path, dfn: dfs number, rnk: rank of dfs number
auto tree_build(ll u) -> ll {
    siz[u] = 1;
    for (auto v : E[u]) {
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        siz[u] += tree_build(v);
        if (siz[v] > siz[son[u]]) {
            son[u] = v;
        }
    }
    return siz[u];
}
auto tree_decomposition(ll u, ll tp) -> void {
    top[u] = tp;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (son[u]) {
        tree_decomposition(son[u], tp);
        for (auto v : E[u]) {
            if (v == son[u] || v == fa[u]) {
                continue;
            }
            tree_decomposition(v, v);
        }
    }
}
auto lca(int u, int v) -> ll {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = fa[top[u]];
        } else {
            v = fa[top[v]];
        }
    }
    return dep[u] > dep[v] ? v : u;
}
void solve() {
    cin >> n >> m >> s;
    for (ll i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    tree_build(s);
    tree_decomposition(s, s);
    for (ll i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}