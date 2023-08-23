#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
namespace atcoder {

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
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return e();

    l += size;
    r += size;

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
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1)
          all_apply(l++, f);
        if (r & 1)
          all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

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
  int _n, size, log;
  std::vector<S> d;
  std::vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size)
      lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};

} // namespace atcoder
using namespace atcoder;
struct node {
  array<ll, 4> sum;
  int len;
};
node op(node l, node r) {
  node x;
  for (int i = 0; i < 4; ++i) {
    x.sum[i] = l.sum[i] + r.sum[i];
  }
  x.len = l.len + r.len;
  return x;
}

node e() {
  node x;
  fill(x.sum.begin(), x.sum.end(), 0);
  x.len = 0;
  return x;
}
struct F {
  ll add;
};
node mapping(F f, node x) {
  f.add %= 4;
  node y = x;
  for (int i = 0; i < 4; ++i) {
    y.sum[i] = x.sum[(i + f.add + 4) % 4];
  }
  return y;
}
F composition(F f, F g) {
  // f(g())
  return F{f.add + g.add};
}
F id() { return F{0}; }
constexpr int inf = 1e5 + 7;
auto solve() {
  int n, m;
  cin >> n >> m;
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(inf * 2);
  vector<pair<int, int>> a(n);
  ll ans = 0;
  for (auto &[l, r] : a)
    cin >> l >> r, ans += r;
  auto dif = a;
  sort(dif.begin(), dif.end(),
       [&](auto x, auto y) { return x.first - x.second < y.first - y.second; });
  for (int i = 0; i < n; ++i) {
    auto node = seg.get(dif[i].first - dif[i].second + inf);
    node.len++;
    node.sum[i % 4] += dif[i].first - dif[i].second;
    seg.set(dif[i].first - dif[i].second + inf, node);
  }
  function<void(int id, int x, int y)> update = [&](int id, int x, int y) {
    auto [pre_x, pre_y] = a[id];
    int len = seg.prod(0, inf + pre_x - pre_y).len;
    // cout<<len<<" ";
    auto node = seg.get(pre_x - pre_y + inf);
    node.len--;
    node.sum[len % 4] -= pre_x - pre_y;
    seg.set(pre_x - pre_y + inf, node);
    seg.apply(pre_x - pre_y + inf, inf * 2, {1});
    seg.apply(x - y + inf, inf * 2, {-1});
    len = seg.prod(0, inf + x - y).len;
    // cout << len << " \n";
    node = seg.get(x - y + inf);
    node.len++;
    node.sum[len % 4] += x - y;
    seg.set(x - y + inf, node);
    a[id] = {x, y};
    ans = ans - pre_y + y;
  };
  function<ll()> cal = [&]() {
    auto l = seg.prod(0, inf);
    auto r = seg.prod(inf, inf * 2);
    // cout<<l.sum[0]<<" "<<l.sum[1]<<" "<<l.sum[2]<<" "<<l.sum[3]<<", ";
    // cout<<r.sum[0]<<" "<<r.sum[1]<<" "<<r.sum[2]<<" "<<r.sum[3]<<", ";
    return l.sum[0] + l.sum[3] + r.sum[0] + r.sum[2];
  };
  cout << cal() + ans << "\n";
  while (m--) {
    int t, x, y;
    cin >> t >> x >> y;
    t--;
    update(t, x, y);
    cout << ans + cal() << "\n";
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