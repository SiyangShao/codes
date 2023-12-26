#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 20;
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
};
struct XORBase {
  array<int, N> p;
  deque<pair<int, int>> used;
  XORBase() {
    fill(p.begin(), p.end(), 0);
    used.clear();
  }
  bool find(int u) {
    for (int i = N - 1; i >= 0; --i) {
      if (!(u >> i))
        continue;
      if (!p[i])
        return false;
      u ^= p[i];
    }
    return true;
  }
  void insert(const int u, int id) {
    int tmp = u;
    used.emplace_back(u, id);
    for (int i = N - 1; i >= 0; --i) {
      if (!(tmp >> i))
        continue;
      if (!p[i]) {
        p[i] = tmp;
        return;
      }
      tmp ^= p[i];
    }
    fill(p.begin(), p.end(), 0);
    deque<pair<int, int>> aft;
    for (auto [nu, nid] : ranges::views::reverse(used)) {
      tmp = nu;
      bool flag = false;
      for (int i = N - 1; i >= 0; --i) {
        if (!(tmp >> i))
          continue;
        if (!p[i]) {
          p[i] = tmp;
          flag = true;
          break;
        }
        tmp ^= p[i];
      }
      if (flag) {
        aft.emplace_front(nu, nid);
      }
    }
    swap(aft, used);
  }
  array<int, N> newBase(int id) {
    array<int, N> bs;
    fill(bs.begin(), bs.end(), 0);
    for (auto [u, nid] : ranges::views::reverse(used)) {
      if (nid < id)
        break;
      for (int i = N - 1; i >= 0; --i) {
        if (!(u >> i))
          continue;
        if (!bs[i]) {
          bs[i] = u;
          break;
        }
        u ^= bs[i];
      }
    }
    return bs;
  }
};
void insert(array<int, N> &x, int u) {
  int tmp = u;
  for (int i = N - 1; i >= 0; --i) {
    if (!(tmp >> i))
      continue;
    if (!x[i]) {
      x[i] = tmp;
      return;
    }
    tmp ^= x[i];
  }
}
array<int, N> merge(const array<int, N> &x, const array<int, N> &y) {
  array<int, N> nw;
  fill(nw.begin(), nw.end(), 0);
  for (auto i : x) {
    if (i == 0)
      continue;
    insert(nw, i);
  }
  for (auto i : y) {
    if (i == 0)
      continue;
    insert(nw, i);
  }
  return nw;
}
bool find(int u, const array<int, N> &p) {
  for (int i = N - 1; i >= 0; --i) {
    if (!(u >> i))
      continue;
    if (!p[i])
      return false;
    u ^= p[i];
  }
  return true;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<vector<int>> E(n);
  heavy_light_decomposition hld(n);
  for ([[maybe_unused]] auto _ : ranges::views::iota(1, n)) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    hld.add_edge(u, v);
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  hld.tree_build(0);
  hld.tree_decomposition(0, 0);
  vector<XORBase> bs(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    bs[u].insert(a[u], hld.dfn[u]);
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      bs[v] = bs[u];
      dfs(v, u);
    }
  };
  dfs(0, 0);
  int q;
  cin >> q;
  while (q--) {
    int u, v, k;
    cin >> u >> v >> k;
    u--, v--;
    int fa = hld.lca(u, v);
    auto lef = bs[u].newBase(hld.dfn[fa]);
    auto rig = bs[v].newBase(hld.dfn[fa]);
    auto nw = merge(lef, rig);
    if (find(k, nw)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
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