#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
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
struct node {
  ll odd, even;
};
node op(node l, node r) { return node{max(l.odd, r.odd), max(l.even, r.even)}; }
node e() { return {0, 0}; }
using F = int;
node mapping(F f, node x) { return x; }
F composition(F f, F g) { return max(f, g); } // f(g())
F id() { return F{-1}; }

struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<pair<int, ll>>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), E(_n) {
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

      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += tree_build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]])
        son[u] = v;
    }
    return siz[u];
  }
  void tree_decomposition(int u, int tp, auto &seg) {
    top[u] = tp, dfn[u] = ++tot, rnk[tot] = u;
    if (son[u] != -1) {
      tree_decomposition(son[u], tp, seg);
      for (auto [v, w] : E[u]) {
        if (v == son[u] || v == fa[u])
          continue;
        tree_decomposition(v, v, seg);
      }
    }
    for (auto [v, w] : E[u]) {
      if (v == fa[u])
        continue;
      node nd;
      if (w % 2 == 0) {
        nd = node{0, w};
      } else {
        nd = node{w, 0};
      }
      seg.set(dfn[v], nd);
    }
  }
  auto cal(int u, int v, auto &seg) {
    node ans{0, 0};
    while (top[u] != top[v])
      if (dep[top[u]] > dep[top[v]]) {
        // jump from u to top[u]
        ans = op(ans, seg.prod(dfn[top[u]], dfn[u] + 1));
        u = fa[top[u]];
      } else {
        ans = op(ans, seg.prod(dfn[top[v]], dfn[v] + 1));
        v = fa[top[v]];
      }
    if (dep[u] > dep[v])
      swap(u, v);
    // assert(false);
    if (u == v)
      return ans;
    ans = op(ans, seg.prod(dfn[u] + 1, dfn[v] + 1));
    return ans;
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
struct DSU {
  vector<int> fa, sz;
  DSU(int n) : fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (sz[u] > sz[v])
      swap(u, v);
    fa[u] = v;
    sz[v] += sz[u];
    return true;
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, ll>> edg(m);
  vector<vector<pair<int, ll>>> E(n);
  for (auto &[u, v, w] : edg) {
    cin >> u >> v >> w;
    u--, v--;
  }
  sort(edg.begin(), edg.end(),
       [&](auto &a, auto &b) { return get<2>(a) < get<2>(b); });
  DSU dsu(n);
  heavy_light_decomposition hld(n);
  vector<tuple<int, int, ll>> other;
  ll ans = 0;
  for (auto [u, v, w] : edg) {
    if (dsu.merge(u, v)) {
      // u-v-w is a MST edge
      hld.add_edge(u, v, w);
      ans += w;
    } else {
      other.emplace_back(u, v, w);
    }
  }
  for (int i = 1; i < n; ++i) {
    if (dsu.find(i) != dsu.find(0)) {
      cout << "-1 -1\n";
      return;
    }
  }
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(n);
  hld.tree_build(0);
  hld.tree_decomposition(0, 0, seg);
  constexpr ll inf = 1e16;
  ll ans2 = inf;
  for (auto [u, v, w] : other) {
    auto nd = hld.cal(u, v, seg);
    if (w % 2 == 0) {
      if (nd.odd == 0) {
        continue;
      }
      ans2 = min(ans2, ans - nd.odd + w);
    } else {
      if (nd.even == 0) {
        continue;
      }
      ans2 = min(ans2, ans - nd.even + w);
    }
  }
  if (ans2 == inf) {
    ans2 = -1;
  }
  if (ans % 2 == 0) {
    cout << ans << " " << ans2 << "\n";
  } else {
    cout << ans2 << " " << ans << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}