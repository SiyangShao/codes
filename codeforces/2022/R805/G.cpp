#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct heavy_light_decomposition {
    int n, m, s, tot;
    vector<int> fa, dep, siz, son, top, dfn, rnk;
    // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
    // top: top of path, dfn: dfs number, rnk: rank of dfs number
    vector<vector<int>> E;
    heavy_light_decomposition(int _n) : n(_n) {
        E.assign(n, vector<int>());
        fa.assign(n, 0), dep.assign(n, 0), son.assign(n, -1), top.assign(n, -1),
            dfn.resize(n), rnk.resize(n), siz.assign(n, 0), tot = -1;
    }
    void add_edge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
    int tree_build(int u) {
        siz[u] = 1;
        for (auto v : E[u]) {
            if (v == fa[u]) {
                continue;
            }
            fa[v] = u;
            dep[v] = dep[u] + 1;
            siz[u] += tree_build(v);
            if (son[u] == -1 || siz[v] > siz[son[u]]) {
                son[u] = v;
            }
        }
        return siz[u];
    }
    void tree_decomposition(int u, int tp) {
        // cout<<u<<" "<<tp<<"\n";
        top[u] = tp;
        dfn[u] = ++tot;
        rnk[tot] = u;
        if (son[u] != -1) {
            tree_decomposition(son[u], tp);
            for (auto v : E[u]) {
                if (v == son[u] || v == fa[u]) {
                    continue;
                }
                tree_decomposition(v, v);
            }
        }
    }
    auto lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = fa[top[u]];
            } else {
                v = fa[top[v]];
            }
        }
        return dep[u] > dep[v] ? v : u;
    }
};
auto solve() {
    ll n;
    cin >> n;
    heavy_light_decomposition G(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }
    G.tree_build(0);
    G.tree_decomposition(0, 0);
    ll q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        vector<ll> p(k);
        for (auto &i : p) {
            cin >> i;
            i--;
        }
        if (k <= 2) {
            cout << "YES\n";
            continue;
        }
        sort(p.begin(), p.end(),
             [&](ll a, ll b) { return G.dep[a] > G.dep[b]; });

        ll u = p[0], v = p[1];
        for (ll i = 1; i < k; ++i) {
            if (G.lca(u, p[i]) != p[i]) {
                v = p[i];
                break;
            }
        }
        ll ans = G.lca(u, v);
        // cout<<u+1<<" "<<v+1<<" "<<ans+1<<"\n";
        if (ans == u || ans == v) {
            cout << "YES\n";
        } else {
            bool flag = true;
            for (ll i = 0; i < k; ++i) {
                if ((G.lca(u, p[i]) != p[i] && G.lca(v, p[i]) != p[i]) ||
                    G.lca(ans, p[i]) != ans) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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
// 4 5 3 4 2
