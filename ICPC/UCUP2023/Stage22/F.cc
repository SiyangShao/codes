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
  vector<ll> dp;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<pair<int, ll>>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), dp(_n), E(_n) {
    tot = -1;
  }
  void add_edge(int u, int v, ll w) {
    E[u].emplace_back(v, w), E[v].emplace_back(u, w);
  }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto [v, w] : E[u]) {
      if (v == fa[u])
        continue;
      dp[v] = dp[u] + w;
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
      for (auto [v, w] : E[u]) {
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
  auto cost(int u, int v) { return dp[u] + dp[v] - 2 * dp[lca(u, v)]; }
};
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> w(n);
  for (auto &i : w)
    cin >> i;
  heavy_light_decomposition G(n);
  for (int i = 1, u, v, len; i < n; ++i) {
    cin >> u >> v >> len;
    u--, v--;
    G.add_edge(u, v, len);
  }
  G.tree_build(0);
  G.tree_decomposition(0, 0);
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int i, int j) { return w[i] < w[j]; });
  int mex = n;
  vector<tuple<ll, int, int>> diameter;
  for (int i = 0; i < n; ++i) {
    if (w[id[i]] != i) {
      mex = i;
      break;
    }
    if (diameter.empty()) {
      diameter.emplace_back(0, id[i], id[i]);
    } else {
      auto [len, x, y] = diameter.back();
      ll lef = G.cost(x, id[i]), rig = G.cost(y, id[i]);
      if (lef >= rig && len < lef) {
        diameter.emplace_back(lef, x, id[i]);
      } else if (lef < rig && len < rig) {
        diameter.emplace_back(rig, y, id[i]);
      } else {
        diameter.emplace_back(len, x, y);
      }
    }
  }
  while (q--) {
    int x;
    ll k;
    cin >> x >> k;
    x--;
    int lef = 0, rig = mex;
    int ans = mex;
    while (lef <= rig) {
      int mid = (lef + rig) / 2;
      ll mx = 0;
      if (mid == mex) {
        mx = 0;
      } else {
        mx = max(mx, G.cost(x, get<1>(diameter[mid])));
        mx = max(mx, G.cost(x, get<2>(diameter[mid])));
      }
      if (mx <= k) {
        lef = mid + 1;
      } else {
        ans = min(ans, mid);
        rig = mid - 1;
      }
    }
    cout << ans << "\n";
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