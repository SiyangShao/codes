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
using node = ll;
constexpr ll inf = 1e16;
node op(node l, node r) { return min(l, r); }
node e() { return inf; }
using F = long long;
node mapping(F f, node x) { return f + x; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
vector<ll> cal_R(int n, const vector<ll> &h) {
  vector<ll> R(n);
  auto discrete = h;
  for (int i = 0; i < n; ++i) {
    discrete[i] += i;
  }
  sort(discrete.begin(), discrete.end());
  discrete.erase(unique(discrete.begin(), discrete.end()), discrete.end());
  auto getid = [&](ll i) {
    return (int)(lower_bound(discrete.begin(), discrete.end(), h[i] + i) -
                 discrete.begin());
  };
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(
      (int)discrete.size());
  for (ll i = n - 1; i >= 0; --i) {
    auto x = getid(i);
    auto j = seg.prod(0, x);
    if (j >= inf) {
      auto len = (n - 1 - i + 1);
      len = min(len, h[i]);
      R[i] = (h[i] + h[i] - len + 1) * len / 2;
    } else {
      // i - (j-1): still
      auto len = (j - 1) - i + 1;
      R[i] = (h[i] + h[i] - len + 1) * len / 2 + R[j];
    }
    seg.set(x, i);
  }
  return R;
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> h(n);
  ll sum = 0;
  for (auto &i : h)
    cin >> i, sum += i;
  auto R = cal_R(n, h);
  // for(int i = 0 ; i < n; ++i){
  //   cout<<R[i]<<" ";
  // }
  // cout << "\n";
  reverse(h.begin(), h.end());
  auto L = cal_R(n, h);
  reverse(L.begin(), L.end());
  ll ans = sum;
  reverse(h.begin(), h.end());
  for (int i = 0; i < n; ++i) {
    // cout << L[i] << " " << R[i] ;
    ans = min(ans, sum - (L[i] + R[i] - h[i] * 2));
  }
  cout << ans << "\n";
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