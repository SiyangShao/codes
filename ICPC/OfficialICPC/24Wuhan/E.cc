#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), E(_n) {
    tot = -1;
  }
  void add_edge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]])
        son[u] = v;
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp) {
    top[u] = tp, dfn[u] = ++tot, rnk[tot] = u;
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
    while (top[u] != top[v])
      if (dep[top[u]] > dep[top[v]])
        u = fa[top[u]];
      else
        v = fa[top[v]];
    return dep[u] > dep[v] ? v : u;
  }
  auto dis(int u, int v) {
    int mid = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[mid];
  }
};
auto solve() {
  int n;
  cin >> n;
  heavy_light_decomposition hld(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    hld.add_edge(u, v);
  }
  int r, t;
  cin >> r >> t;
  r--;
  hld.tree_build(r);
  hld.tree_decomposition(r, r);
  int max_dep = 0;
  vector<vector<int>> depNode(n, vector<int>());
  for (int i = 0; i < n; ++i) {
    depNode[hld.dep[i]].emplace_back(i);
    max_dep = max(max_dep, hld.dep[i]);
  }
  vector<int> len(max_dep + 1, 0);
  int lefNode = r, rigNode = r;
  for (int i = 1; i <= max_dep; ++i) {
    len[i] = len[i - 1];
    for (auto x : depNode[i]) {
      int lef = hld.dis(lefNode, x);
      int rig = hld.dis(rigNode, x);
      if (max(lef, rig) > len[i]) {
        len[i] = max(lef, rig);
        if (lef > rig) {
          rigNode = x;
        } else {
          lefNode = x;
        }
      }
    }
  }
  auto check = [&](int x, int speed) {
    int myt = min(x, max_dep);
    int curLen = len[myt] / 2 + len[myt] % 2;
    int needTime = curLen / speed + (curLen % speed != 0);
    if (needTime + t <= x) {
      return true;
    } else {
      return false;
    }
  };
  for (int i = 1; i <= n; ++i) {
    int ll = 1, rr = n * 2;
    int ans = rr;
    while (ll <= rr) {
      int mid = (ll + rr) / 2;
      if (check(mid, i)) {
        ans = min(ans, mid);
        rr = mid - 1;
      } else {
        ll = mid + 1;
      }
    }
    cout << ans << " ";
  }
  cout << "\n";
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