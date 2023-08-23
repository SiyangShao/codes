#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
  int x = 0;
  while (!(n & (1 << x)))
    x++;
  return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

} // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() const { return d[1]; }

  template <bool (*f)(S)> int max_right(int l) const {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F> int max_right(int l, F f) const {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n)
      return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
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

  template <bool (*f)(S)> int min_left(int r) const {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F> int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0)
      return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
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
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
constexpr ll inf = 1e9;
ll op(ll x, ll y) { return min(x, y); }
ll e() { return inf; }
segtree<ll, op, e> seg;
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
      for (auto v : E[u]) {
        if (v == son[u] || v == fa[u]) {
          continue;
        }
        tree_decomposition(v, v);
      }
    }
  }
  auto lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = fa[top[u]];
      } else {
        v = fa[top[v]];
      }
    }
    return dep[u] > dep[v] ? v : u;
  }
  auto min_path(int u, int ance) {
    assert(dep[u] >= dep[ance]);
    ll ans = inf;
    while (top[u] != top[ance]) {
      assert(top[u] != 0);
      ans = min(ans, seg.prod(dfn[top[u]], dfn[u] + 1));
      u = fa[top[u]];
    }
    ans = min(ans, seg.prod(dfn[ance] + 1, dfn[u] + 1));
    return ans;
  }
};
struct virtual_tree {
  heavy_light_decomposition &G;
  vector<vector<int>> E;
  virtual_tree(heavy_light_decomposition &ptr) : G(ptr), E(ptr.n){};
  void build(vector<int> &node) {
    sort(node.begin(), node.end(),
         [&](int x, int y) { return G.dfn[x] < G.dfn[y]; });
    E[0].clear();
    stack<int> st;
    st.emplace(0);
    for (auto x : node) {
      E[x].clear();
      int top = G.lca(x, st.top());
      if (top == st.top()) {
        st.emplace(x);
        continue;
      }
      auto u = st.top();
      st.pop();
      while (!st.empty() && G.dep[st.top()] > G.dep[top]) {
        E[st.top()].emplace_back(u);
        u = st.top();
        st.pop();
      }
      if (!st.empty() && top == st.top()) {
        E[top].emplace_back(u);
      } else {
        E[top].clear();
        E[top].emplace_back(u);
        st.emplace(top);
      }
      st.emplace(x);
    }
    int u = st.top();
    st.pop();
    while (!st.empty()) {
      E[st.top()].emplace_back(u);
      u = st.top();
      st.pop();
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  heavy_light_decomposition G(n);
  map<pair<int, int>, ll> rd;
  for (int i = 1; i < n; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    G.add_edge(u, v);
    rd[{u, v}] = rd[{v, u}] = w;
  }
  vector<ll> val(n, 0);
  G.tree_build(0);
  G.tree_decomposition(0, 0);
  function<void(int, int, ll)> dfs = [&](int u, int fa, ll w) {
    val[G.dfn[u]] = w;
    for (auto v : G.E[u]) {
      if (v == fa)
        continue;
      dfs(v, u, rd[{u, v}]);
    }
  };
  dfs(0, 0, 0);
  seg = segtree<ll, op, e>(val);
  virtual_tree E(G);
  int m;
  cin >> m;
  while (m--) {
    int k;
    cin >> k;
    vector<int> island(k);
    set<int> critical;
    for (auto &i : island) {
      cin >> i;
      i--;
      critical.emplace(i);
    }
    E.build(island);
    auto &&EE = E.E;
    function<ll(int, int)> dp = [&](int u, int fa) {
      ll ans = 0;
      if (EE[u].empty())
        return inf;
      for (auto v : EE[u]) {
        if (v == fa)
          continue;
        if (critical.contains(v)) {
          ans += G.min_path(v, u);
        } else {
          ans += min(G.min_path(v, u), dp(v, u));
        }
      }
      return ans;
    };
    cout << dp(0, 0) << "\n";
  }
}