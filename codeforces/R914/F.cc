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
  vector<int> fa, dep, siz, son, top, dfn, rnk, out;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  vector<vector<pair<int, int>>> whichSon;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), out(_n), E(_n), whichSon(_n) {
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
      // cout << dfn[u] << " " << dfn[son[u]] << endl;
      whichSon[u].emplace_back(dfn[son[u]], son[u]);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u])
          continue;
        tree_decomposition(v, v);
        // cout << dfn[u] << " " << dfn[v] << endl;
        whichSon[u].emplace_back(dfn[v], v);
      }
    }
    out[u] = tot + 1;
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
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  heavy_light_decomposition G(n);
  for ([[maybe_unused]] auto _ : ranges::views::iota(1, n)) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G.add_edge(u, v);
  }
  G.tree_build(0);
  G.tree_decomposition(0, 0);
  const int log = ceil_pow2(n), size = 1 << log;
  vector<int> large(2 * size, -1), small(2 * size, -1);
  for (int i = 0; i < n; ++i) {
    large[size + G.dfn[i]] = small[size + G.dfn[i]] = i;
  }
  int tmp = n;
  for (int i = size - 1; i >= 1; --i) {
    large[i] = tmp++;
    small[i] = tmp++;
  }
  dbg(large, small);
  vector<vector<int>> E(tmp);
  for (int i = size - 1; i >= 1; --i) {
    if (large[2 * i] != -1)
      E[large[i]].emplace_back(large[2 * i]);
    if (large[2 * i + 1] != -1)
      E[large[i]].emplace_back(large[2 * i + 1]);
    if (small[2 * i] != -1)
      E[small[2 * i]].emplace_back(small[i]);
    if (small[2 * i + 1] != -1)
      E[small[2 * i + 1]].emplace_back(small[i]);
  }
  function<void(int, int, int)> rangeToPoint = [&](int l, int r, int x) {
    // l - r smallest on x
    // cout << l << " " << r << " " << x << endl;
    if (l == r)
      return;
    if (x < r && x >= l) {
      rangeToPoint(l, x, x);
      rangeToPoint(x + 1, r, x);
      return;
    }
    l += size, r += size, x += size;
    while (l < r) {
      if (l & 1) {
        E[small[l++]].emplace_back(small[x]);
      }
      if (r & 1) {
        E[small[--r]].emplace_back(small[x]);
      }
      l >>= 1, r >>= 1;
    }
  };
  function<void(int, int, int)> pointToRange = [&](int l, int r, int x) {
    // l - r largest on x
    // cout << l << " " << r << " " << x << endl;
    if (l == r)
      return;
    if (x < r && x >= l) {
      pointToRange(l, x, x);
      pointToRange(x + 1, r, x);
      return;
    }
    l += size, r += size, x += size;
    while (l < r) {
      if (l & 1) {
        E[large[x]].emplace_back(large[l++]);
      }
      if (r & 1) {
        E[large[x]].emplace_back(large[--r]);
      }
      l >>= 1, r >>= 1;
    }
  };
  while (m--) {
    int t, u, v, x;
    cin >> t >> u >> v >> x;
    u--, v--, x--;
    while (G.top[u] != G.top[v]) {
      if (G.dep[G.top[u]] > G.dep[G.top[v]]) {
        if (t == 1) {
          rangeToPoint(G.dfn[G.top[u]], G.dfn[u] + 1, G.dfn[x]);
        } else {
          pointToRange(G.dfn[G.top[u]], G.dfn[u] + 1, G.dfn[x]);
        }
        u = G.fa[G.top[u]];
      } else {
        if (t == 1) {
          rangeToPoint(G.dfn[G.top[v]], G.dfn[v] + 1, G.dfn[x]);
        } else {
          pointToRange(G.dfn[G.top[v]], G.dfn[v] + 1, G.dfn[x]);
        }
        v = G.fa[G.top[v]];
      }
    }
    if (G.dep[u] > G.dep[v]) {
      if (t == 1) {
        rangeToPoint(G.dfn[v], G.dfn[u] + 1, G.dfn[x]);
      } else {
        pointToRange(G.dfn[v], G.dfn[u] + 1, G.dfn[x]);
      }
    } else {
      if (t == 1) {
        rangeToPoint(G.dfn[u], G.dfn[v] + 1, G.dfn[x]);
      } else {
        pointToRange(G.dfn[u], G.dfn[v] + 1, G.dfn[x]);
      }
    }
  }
  dbg(E);
  vector<int> in(tmp), vis(tmp);
  vector<int> ans(n);
  for (int u = 0; u < tmp; ++u) {
    for (auto v : E[u]) {
      if (v == -1)
        continue;
      in[v]++;
    }
  }
  queue<int> Q;
  dbg(in);
  for (int i = 0; i < tmp; ++i) {
    if (in[i] == 0)
      Q.emplace(i);
  }
  int cnt = n;
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    vis[u] = 1;
    if (u < n) {
      ans[u] = cnt--;
    }
    for (auto v : E[u]) {
      if (v == -1)
        continue;
      in[v]--;
      if (in[v] == 0)
        Q.emplace(v);
    }
  }
  dbg(vis);
  for (auto i : vis) {
    if (i == 0) {
      cout << "-1\n";
      return;
    }
  }
  for (auto i : ranges::views::iota(0, n)) {
    cout << ans[i] << " ";
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