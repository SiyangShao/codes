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
      whichSon[u].emplace_back(dfn[son[u]], son[u]);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u])
          continue;
        tree_decomposition(v, v);
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
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
public:
  lazy_segtree() : lazy_segtree(0){};
  explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}
  explicit lazy_segtree(const vector<S> &v) : _n(int(v.size())) {
    log = ceil_pow2(_n), size = 1 << log, d = vector<S>(2 * size, e()),
    lz = vector<F>(size, id());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--)
      update(i);
  }
  void set(int p, S x) {
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }
  S get(int p) {
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    return d[p];
  }
  S prod(int l, int r) {
    if (l == r)
      return e();
    l += size, r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }
    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1, r >>= 1;
    }
    return op(sml, smr);
  }
  void apply(int p, F f) {
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(l <= r);
    if (l == r)
      return;
    l += size, r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }
    int l2 = l, r2 = r;
    while (l < r) {
      if (l & 1)
        all_apply(l++, f);
      if (r & 1)
        all_apply(--r, f);
      l >>= 1, r >>= 1;
    }
    l = l2, r = r2;
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l)
        update(l >> i);
      if (((r >> i) << i) != r)
        update((r - 1) >> i);
    }
  }
  template <bool (*g)(S)> int max_right(int l) {
    return max_right(l, [](S x) { return g(x); });
  }
  template <class G> int max_right(int l, G g) {
    assert(0 <= l && l <= _n);
    assert(g(e()));
    if (l == _n)
      return _n;
    l += size;
    for (int i = log; i >= 1; i--)
      push(l >> i);
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!g(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (g(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*g)(S)> int min_left(int r) {
    return min_left(r, [](S x) { return g(x); });
  }
  template <class G> int min_left(int r, G g) {
    assert(0 <= r && r <= _n);
    assert(g(e()));
    if (r == 0)
      return 0;
    r += size;
    for (int i = log; i >= 1; i--)
      push((r - 1) >> i);
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!g(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (g(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

private:
  int _n{}, size{}, log{};
  vector<S> d;
  vector<F> lz;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size)
      lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]), all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
  int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n))
      x++;
    return x;
  }
};
using node = ll;
node op(node l, node r) { return max(l, r); }
node e() { return -1e9; }
using F = long long;
node mapping(F f, node x) { return x + f; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
auto solve() {
  int n, q;
  cin >> n >> q;
  heavy_light_decomposition E(n);
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(n);
  for ([[maybe_unused]] auto _ : ranges::views::iota(1, n)) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E.add_edge(u, v);
  }
  E.tree_build(0);
  E.tree_decomposition(0, 0);
  for (auto u : ranges::views::iota(0, n)) {
    seg.set(E.dfn[u], E.dep[u]);
  }
  vector<ll> ans(q);
  vector<vector<pair<int, vector<int>>>> query(n);
  for (auto i : ranges::views::iota(0, q)) {
    int x, k;
    cin >> x >> k;
    x--;
    vector<int> a(k);
    for (auto &j : a) {
      cin >> j;
      j--;
    }
    query[x].emplace_back(i, a);
  }
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (const auto &[queryId, a] : query[u]) {
      for (auto v : a) {
        auto lef = E.dfn[v], rig = E.out[v];
        auto p = E.lca(u, v);
        if (p == v) {
          auto it = upper_bound(E.whichSon[v].begin(), E.whichSon[v].end(),
                                pair{E.dfn[u], (int)1e9});
          assert(it != E.whichSon[v].begin());
          it = prev(it);
          lef = E.dfn[it->second], rig = E.out[it->second];
          seg.apply(0, lef, -1e9);
          seg.apply(rig, n, -1e9);
        } else {
          seg.apply(lef, rig, -1e9);
        }
      }
      ans[queryId] = seg.prod(0, n);
      for (auto v : a) {
        auto lef = E.dfn[v], rig = E.out[v];
        auto p = E.lca(u, v);
        if (p == v) {
          auto it = upper_bound(E.whichSon[v].begin(), E.whichSon[v].end(),
                                pair{E.dfn[u], (int)1e9});
          assert(it != E.whichSon[v].begin());
          it = prev(it);
          lef = E.dfn[it->second], rig = E.out[it->second];
          seg.apply(0, lef, 1e9);
          seg.apply(rig, n, 1e9);
        } else {
          seg.apply(lef, rig, 1e9);
        }
      }
    }
    for (auto v : E.E[u]) {
      if (v == fa)
        continue;
      auto lef = E.dfn[v], rig = E.out[v];
      seg.apply(lef, rig, -1);
      seg.apply(0, lef, 1);
      seg.apply(rig, n, 1);
      dfs(v, u);
      seg.apply(lef, rig, 1);
      seg.apply(0, lef, -1);
      seg.apply(rig, n, -1);
    }
  };
  dfs(0, 0);
  for (auto i : ans) {
    cout << i << "\n";
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