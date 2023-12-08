#include <bits/stdc++.h>

#include <utility>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;

constexpr int N = 20;
using node = array<int, N>;
void insert(node &p, int x) {
  if (x == 0)
    return;
  for (int i = N - 1; i >= 0; --i) {
    if (!(x >> i))
      continue;
    if (!p[i]) {
      p[i] = x;
      break;
    }
    x ^= p[i];
  }
}
bool find(node &p, int x) {
  if (x == 0)
    return true;
  for (int i = N - 1; i >= 0; --i) {
    if (!(x >> i))
      continue;
    if (!p[i]) {
      return false;
    }
    x ^= p[i];
  }
  return true;
}
void merge(node &l, const node &r) {
  bool flag = true;
  for (int i = 0; i < N; ++i) {
    if (l[i] == 0) {
      flag = false;
      break;
    }
  }
  if (flag)
    return;
  for (int i = N - 1; i >= 0; --i) {
    insert(l, r[i]);
  }
}
class SparseTable {
  using T = node;
  using VT = vector<T>;
  using VVT = vector<VT>;
  VVT ST;
  vector<int> LOG, POW;
  T tmp;
  T op(const T &t1, const T &t2) {
    tmp = t1;
    merge(tmp, t2);
    return tmp;
  }

public:
  SparseTable() {}
  SparseTable(const vector<T> &v) {
    int len = (int)v.size(), l1 = (int)ceil(log2(len)) + 1;
    ST = VVT(len, VT(l1));
    LOG = vector<int>(len + 1, 0);
    POW = vector<int>(len + 1, 1);
    for (int i = 0; i < len; ++i) {
      ST[i][0] = v[i];
      if (i > 0 && i <= 30) {
        POW[i] = POW[i - 1] * 2;
      }
    }
    for (int i = 2; i <= len; ++i) {
      LOG[i] = LOG[i / 2] + 1;
    }
    for (int j = 1; j < l1; ++j) {
      int pj = (1 << (j - 1));
      for (int i = 0; i + pj < len; ++i) {
        ST[i][j] = ST[i][j - 1];
        merge(ST[i][j], ST[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T query(int l, int r) {
    int lt = r - l + 1;
    int q = LOG[lt];
    dbg(ST[l][q], ST[r - POW[q] + 1][q]);
    return op(ST[l][q], ST[r - POW[q] + 1][q]);
  }
};
SparseTable sp;
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
  node newLCA(int u, int v) {
    node val;
    fill(val.begin(), val.end(), 0);
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        merge(val, sp.query(dfn[top[u]], dfn[u]));
        u = fa[top[u]];
      } else {
        merge(val, sp.query(dfn[top[v]], dfn[v]));
        v = fa[top[v]];
      }
    }
    if (dep[u] > dep[v]) {
      merge(val, sp.query(dfn[v], dfn[u]));
    } else {
      merge(val, sp.query(dfn[u], dfn[v]));
    }
    return val;
  }
};

auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  heavy_light_decomposition hld(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    hld.add_edge(u, v);
  }
  hld.tree_build(0);
  hld.tree_decomposition(0, 0);
  vector<node> b(n);
  for (int i = 0; i < n; ++i) {
    insert(b[hld.dfn[i]], a[i]);
  }
  sp = SparseTable(b);
  int q;
  cin >> q;
  while (q--) {
    int x, y, k;
    cin >> x >> y >> k;
    x--, y--;
    node tmp = hld.newLCA(x, y);
    dbg(tmp);
    if (find(tmp, k)) {
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