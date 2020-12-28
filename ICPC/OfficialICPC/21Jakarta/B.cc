#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct hld {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  vector<vector<int>> E;
  hld(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), E(_n) {
    tot = -1;
  }
  void addEdge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
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
    top[u] = tp;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u])
          continue;
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
struct DSU {
  vector<int> fa, siz;
  DSU(int n) : fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    fa[u] = v;
    siz[v] += siz[u];
    return true;
  }
};

auto solve() {
  int n, M;
  cin >> n >> M;
  vector<int> h(n);
  for (auto &i : h) {
    cin >> i;
  }
  vector<tuple<int, int, int>> edg(M);
  for (auto &[w, u, v] : edg) {
    cin >> u >> v;
    u--, v--;
    w = abs(h[u] - h[v]);
  }
  sort(edg.begin(), edg.end());
  DSU dsu(n);
  hld G(n);
  vector<pair<int, int>> check;
  for (auto [w, u, v] : edg) {
    if (dsu.merge(u, v)) {
      G.addEdge(u, v);
    } else {
      check.emplace_back(u, v);
    }
  }
  G.tree_build(0);
  G.tree_decomposition(0, 0);

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