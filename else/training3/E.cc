#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
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
  void clear() {
    fa = vector<int>(n, -1);
    son = vector<int>(n, -1);
    top = vector<int>(n, -1);
    tot = -1;
  }
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
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * qpow(2, MOD - 2) % MOD;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    hld.clear();
    hld.tree_build(i);
    hld.tree_decomposition(i, i);
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < j; ++k) {
        int lc = hld.lca(j, k);
        int depj = hld.dep[j] - hld.dep[lc];
        int depk = hld.dep[k] - hld.dep[lc];
        ans = (ans + dp[depj][depk]) % MOD;
      }
    }
  }
  ans = ans * qpow(n, MOD - 2) % MOD;
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