#include <bits/stdc++.h>
using namespace std;
namespace atcoder {
namespace internal {

#if __cplusplus >= 202002L

using std::bit_ceil;

#else

// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
  unsigned int x = 1;
  while (x < (unsigned int)(n))
    x *= 2;
  return x;
}

#endif

// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
  int x = 0;
  while (!(n & (1 << x)))
    x++;
  return x;
}

} // namespace internal

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
  static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                "op must work as S(S, S)");
  static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
    size = (int)internal::bit_ceil((unsigned int)(_n));
    log = internal::countr_zero((unsigned int)size);
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
    // cout << "DEBUG:" << l << " " << r << " " << _n << endl;
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
// struct node_max {
//   vector<pair<int,int>> pii;
// };
using node_min = array<int, 32>;
auto op_min(node_min x, node_min y) {
  array<int, 32> ans;
  for (int i = 0; i < 32; ++i) {
    ans[i] = min(x[i], y[i]);
  }
  return ans;
}
node_min e_min() {
  node_min x;
  fill(x.begin(), x.end(), 32);
  return x;
}
using node_special = array<int, 32>;
auto op_special(node_special x, node_special y) {
  node_special special;
  for (int i = 0; i < 32; ++i) {
    if (x[i] != -1 && y[i] != -1) {
      special[i] = -2;
    } else if (x[i] != -1) {
      special[i] = x[i];
    } else if (y[i] != -1) {
      special[i] = y[i];
    } else {
      special[i] = -1;
    }
  }
  return special;
}
node_special e_special() {
  node_special tmp;
  fill(tmp.begin(), tmp.end(), -1);
  return tmp;
}
struct node_or {
  int val;
};
node_or op_or(node_or a, node_or b) { return {a.val | b.val}; }
node_or e_or() { return {0}; }

int get_bit(int x) {
  int cnt = 0;
  while (x) {
    x >>= 1;
    cnt++;
  }
  return cnt;
}
auto get_lr(int x) {
  assert(x != 0);
  int BIT = get_bit(x);
  int l = -1, r = 32;
  for (int i = 0; i < BIT; ++i) {
    if (!(x & (1 << i))) {
      r = min(r, i);
      l = max(l, i);
    }
  }
  assert(l != -1 && r != 32);
  return pair<int, int>{l, r};
}
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  atcoder::segtree<node_min, op_min, e_min> seg_min(n);
  vector<array<int, 32>> vvvec(n);
  atcoder::segtree<node_special, op_special, e_special> seg_special(n);
  auto add = [&](int id) {
    int x = a[id];
    int cur = 0;
    auto arr = e_min();
    auto spec = e_special();
    for (int i = 0; i < get_bit(x); ++i) {
      if (!(x & (1 << i))) {
        arr[i] = cur;
      } else {
        if (cur == i - 1) {
          arr[i] = cur;
        }
        cur = i + 1;
        spec[i] = id;
      }
    }
    // cerr << "DEBUG: ";
    // for (int i = 0; i < get_bit(x); ++i) {
    //   cout << arr[i] << " ";
    // }
    // cout << endl;
    vvvec[id] = arr;
    seg_special.set(id, spec);
    seg_min.set(id, arr);
  };
  atcoder::segtree<node_or, op_or, e_or> seg_or(n);
  for (int i = 0; i < n; ++i) {
    add(i);
    seg_or.set(i, {a[i]});
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    // cout << l << " " << r << endl;
    auto or_sum = seg_or.prod(l, r).val;
    int bit = get_bit(or_sum);
    const int max_sum = (1 << bit) - 1;
    cout << max_sum << " ";
    if (max_sum == or_sum) {
      cout << "0\n";
      continue;
    }
    auto check_equal = [&](int id) {
      int x = a[id];
      int other = seg_or.prod(l, id).val | seg_or.prod(id + 1, r).val;
      for (int i = 0; i < 31; ++i) {
        if (x < (1LL << i))
          break;
        if (((x ^ (x - (1 << i))) | other) == max_sum) {
          return true;
        }
      }
      return false;
    };
    auto check = [&]() {
      auto spec = seg_special.prod(l, r);
      set<int> special;
      for (int i = 0; i < 32; ++i) {
        if (spec[i] >= 0) {
          assert(spec[i] < n);
          special.insert(spec[i]);
        }
      }
      for (auto i : special) {
        if (check_equal(i)) {
          return true;
        }
      }
      for (auto i : special) {
        seg_min.set(i, e_min());
      }

      auto [L, R] = get_lr(or_sum);
      auto min_sum = seg_min.prod(l, r);
      for (auto i : special) {
        seg_min.set(i, vvvec[i]);
      }
      return R >= min_sum[L];
    };
    // case 1: 0
    if (check()) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
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