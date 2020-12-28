#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
public:
  lazy_segtree() : lazy_segtree(0){};
  lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}
  lazy_segtree(const vector<S> &v) : _n(int(v.size())) {
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
node e() { return 0; }
using F = ll;
node mapping(F f, node x) { return x + f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
lazy_segtree<node, op, e, F, mapping, composition, id> seg;
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
  int build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      fa[v] = u;
      dep[v] = dep[u] + 1;
      siz[u] += build(v);
      if (son[u] == -1 || siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
    return siz[u];
  }
  void decomposition(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (son[u] != -1) {
      decomposition(son[u], tp);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) {
          continue;
        }
        decomposition(v, v);
      }
    }
  }
  auto lca(int u, int v) {
    ll ans = 0;
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        ans = max(ans, seg.prod(dfn[top[u]], dfn[u] + 1));
        u = fa[top[u]];
      } else {
        ans = max(ans, seg.prod(dfn[top[v]], dfn[v] + 1));
        v = fa[top[v]];
      }
    }
    if (dep[u] > dep[v]) {
      ans = max(ans, seg.prod(dfn[v] + 1, dfn[u] + 1));
    } else {
      ans = max(ans, seg.prod(dfn[u] + 1, dfn[v] + 1));
    }
    return ans;
  }
};
struct DSU {
  vector<int> fa, siz;
  DSU(int n) : fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (siz[u] > siz[v])
      swap(u, v);
    fa[u] = v;
    siz[v] += siz[u];
    return true;
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<ll, int, int>> edg(m);
  vector<tuple<ll, int, int>> used, unused;
  for (auto &[w, u, v] : edg) {
    cin >> u >> v >> w;
    u--, v--;
  }
  sort(edg.begin(), edg.end());
  DSU dsu(n);
  for (auto [w, u, v] : edg) {
    if (dsu.merge(u, v)) {
      used.emplace_back(w, u, v);
    } else {
      unused.emplace_back(w, u, v);
    }
  }
  vector<vector<pair<int, ll>>> E(n);
  dsu = DSU(n);
  int edgnum = 0;
  hld G(n);
  for (auto [w, u, v] : unused) {
    if (dsu.merge(u, v)) {
      G.addEdge(u, v);
      E[u].emplace_back(v, w);
      E[v].emplace_back(u, w);
      edgnum++;
    }
  }
  if (edgnum != n - 1) {
    cout << "-1\n";
    return;
  }
  G.build(0);
  G.decomposition(0, 0);
  seg = lazy_segtree<node, op, e, F, mapping, composition, id>(n);
  vector<ll> a(n, 0);
  for (int u = 0; u < n; ++u) {
    for (auto [v, w] : E[u]) {
      if (v == G.fa[u]) {
        a[u] = w;
        break;
      }
    }
    seg.set(G.dfn[u], a[u]);
  }
  ll ans = 0;
  for (auto [w, u, v] : used) {
    // cout << u + 1 << " " << v + 1 << " + ";
    // cout << max(G.lca(u, v) + 1 - w, 0LL) << "\n";
    ans += max(G.lca(u, v) + 1 - w, 0LL);
  }
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