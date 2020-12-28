#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using l = long long;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool same(int u, int v) { return find(u) == find(v); }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
using ll = long long;
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  vector<ll> a;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  DSU dsu;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), a(_n), E(_n), dsu(_n) {
    tot = -1;
  }
  void add_edge(int u, int v) {
    E[u].emplace_back(v), E[v].emplace_back(u);
    dsu.merge(u, v);
  }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u]) {
        continue;
      }
      fa[v] = u;
      dep[v] = dep[u] + 1;
      a[v] += a[u];
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
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
  auto solve(int x, int y) {
    if (!dsu.same(x, y)) {
      return a[x] + a[y];
    }
    int z = lca(x, y);
    return a[x] + a[y] - a[z];
  }
};
constexpr ll inf = 1e16;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  heavy_light_decomposition G(n);
  vector<int> is_root(n, 1), is_leaf(n, 1);
  for (auto &i : G.a) {
    cin >> i;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    is_root[v] = 0;
    is_leaf[u] = 0;
    G.add_edge(u, v);
  }
  for (int i = 0; i < n; ++i) {
    if (is_root[i]) {
      G.tree_build(i);
      G.tree_decomposition(i, i);
    }
  }
  ll ans = inf;
  for (int i = 0; i < n; ++i) {
    if (!is_leaf[i])
      continue;
    for (int j = i + 1; j < n; ++j) {
      if (!is_leaf[j])
        continue;
      ans = min(ans, G.solve(i, j));
    }
  }
  cout << ans << "\n";
}