#include <bits/stdc++.h>
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

private:
  int _n{}, size{}, log{};
  std::vector<S> d;
  std::vector<F> lz;
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
// struct node {
//   ll sum, len;
// };
using node = long long;
node op(node l, node r) { return max(l, r); }
node e() { return 0; }
using F = long long;
node mapping(F f, node x) { return x + f; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
constexpr int N = 1e3 + 5;
lazy_segtree<node, op, e, F, mapping, composition, id> seg(N);
struct heavy_light_decomposition {
  int n, m, s, tot;
  vector<int> fa, dep, siz, son, top, dfn, rnk;
  vector<set<pair<int, int>>> st;
  // E: edge, fa: father, dep: deep, siz: size of subtree, son: heavy son
  // top: top of path, dfn: dfs number, rnk: rank of dfs number
  vector<vector<int>> E;
  heavy_light_decomposition(int _n)
      : n(_n), fa(_n, -1), dep(_n), siz(_n), son(_n, -1), top(_n, -1), dfn(_n),
        rnk(_n), st(_n), E(_n) {
    tot = -1;
  }
  void add_edge(int u, int v) { E[u].emplace_back(v), E[v].emplace_back(u); }
  int tree_build(int u) {
    siz[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u]) {
        continue;
      }
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
      // st[u].emplace(son[u], dfn[son[u]]);
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) {
          continue;
        }
        tree_decomposition(v, v);
        // st[u].emplace(v, dfn[v]);
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
    if (u == v) {
      return ans;
    }
    if (dep[u] > dep[v]) {
      swap(u, v);
    }
    assert(dep[u] < dep[v]);
    // cout << u << " " << v << ": ";
    // cout << seg.get(dfn[u]) << " " << seg.get(dfn[v]) << endl;
    ans = max(ans, seg.prod(dfn[u] + 1, dfn[v] + 1));
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> cost(n);
  for (auto &i : cost) {
    cin >> i;
  }
  vector<tuple<int, int, ll>> vec(n - 1);
  heavy_light_decomposition hld(n);
  for (auto &[u, v, w] : vec) {
    cin >> u >> v >> w;
    u--, v--;
    hld.add_edge(u, v);
  }
  hld.tree_build(0);
  hld.tree_decomposition(0, 0);
  for (auto &[u, v, w] : vec) {
    if (hld.fa[u] == v) {
      swap(u, v);
    }
    // fa[v] = u
    // cout << w << " ";
    seg.set(hld.dfn[v], w);
    // cout << seg.get(hld.dfn[v]) << "\n";
    // cout << v << " " << hld.dfn[v] << " " << w << "\n";
  }
  vector<vector<ll>> val(n, vector<ll>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      val[i][j] = val[j][i] = hld.lca(i, j);
      // cout << val[i][j] << " ";
    }
    // cout << "\n";
  }
  
}