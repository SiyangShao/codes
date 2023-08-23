#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace atcoder::internal {

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

} // namespace atcoder::internal

namespace atcoder {

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

  [[nodiscard]] S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  [[nodiscard]] S prod(int l, int r) const {
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

  [[nodiscard]] S all_prod() const { return d[1]; }

  template <bool (*f)(S)> [[nodiscard]] int max_right(int l) const {
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

  template <bool (*f)(S)> [[nodiscard]] int min_left(int r) const {
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

} // namespace atcoder

struct dsu {
public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1), boss(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    boss[a] = boss[b] = a;
    int x = leader(a), y = leader(b);
    boss[x] = boss[y] = a;
    if (x == y)
      return x;
    if (-parent_or_size[x] < -parent_or_size[y])
      std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    boss[x] = a;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0)
      return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }
  int get_boss(int a) {
    a = leader(a);
    if (boss[a] == -1) {
      return a;
    } else {
      return boss[a];
    }
  }
  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
  std::vector<int> boss;
};
auto op(pair<int, int> a, pair<int, int> b) { return max(a, b); }
auto e() { return pair<int, int>{0, -1}; }
auto solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (auto &i : p) {
    cin >> i;
  }
  vector<pair<int, int>> edges(m);
  for (auto &[u, v] : edges) {
    cin >> u >> v;
    u--, v--;
  }
  vector<pair<int, int>> querys(q);
  vector<int> ununsed_edge(m);
  for (auto &[i, v] : querys) {
    cin >> i >> v;
    v--;
    if (i == 2) {
      ununsed_edge[v]++;
    }
  }
  dsu DSU(n + m);
  vector<vector<int>> E(n + m);
  for (int i = 0; i < m; ++i) {
    if (!ununsed_edge[i]) {
      auto [u, v] = edges[i];
      u = DSU.get_boss(u);
      v = DSU.get_boss(v);
      if (DSU.same(u, v))
        continue;
      DSU.merge(u, v);
      assert(DSU.get_boss(v) == u);
      E[u].emplace_back(v);
    }
  }
  int new_node = n;
  for (auto it = querys.rbegin(); it < querys.rend(); ++it) {
    auto &[op, i] = *it;
    if (op == 2) {
      auto &[u, v] = edges[i];
      if (DSU.same(u, v))
        continue;
      u = DSU.get_boss(u);
      v = DSU.get_boss(v);
      // E[u].emplace_back(new_node), E[v].emplace_back(new_node);
      DSU.merge(new_node, u);
      DSU.merge(new_node, v);
      assert(DSU.get_boss(u) == new_node && DSU.get_boss(v) == new_node);
      E[new_node].emplace_back(u), E[new_node].emplace_back(v);
      new_node++;
    } else {
      // NOW the root of the subtree which includes node i
      i = DSU.get_boss(i);
    }
  }
  vector<int> dfn(new_node, -1), lst(new_node);
  int _dfn = 0;
  // cout<<new_node<<"::\n";
  function<void(int, int)> dfs = [&](int u, int fa) {
    dfn[u] = _dfn++;
    // cout<<u<<" "<<dfn[u]<<"\n";
    for (auto v : E[u]) {
      if (fa == v)
        continue;
      dfs(v, u);
    }
    lst[u] = _dfn;
  };
  for (int i = 0; i < n; ++i) {
    int root = DSU.get_boss(i);
    if (dfn[root] == -1) {
      dfs(root, root);
    }
  }
  // for(int i = 0 ; i < new_node; ++i){
  //   cout<<dfn[i]<<" ";
  // }
  // cout<<"\n";
  atcoder::segtree<pair<int, int>, op, e> seg(_dfn + 10);
  for (int i = 0; i < n; ++i) {
    seg.set(dfn[i], {p[i], dfn[i]});
  }
  for (auto &[op, v] : querys) {
    if (op == 2)
      continue;
    auto [val, pos] = seg.prod(dfn[v], lst[v]);
    cout << val << "\n";
    seg.set(pos, {0, pos});
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
