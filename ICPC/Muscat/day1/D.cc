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
struct node {
  ll sum, len;
};
node op(node l, node r) { return node{l.sum + r.sum, l.len + r.len}; }
node e() { return node{0, 0}; }
using F = long long;
node mapping(F f, node x) { return node{x.sum + f * x.len, x.len}; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, ll>> query(q);
  vector<ll> val;
  val.emplace_back(0);
  vector<ll> a(n, 0), cur(n, 0), ans(n, 0);
  for (auto &[x, y] : query) {
    cin >> x >> y;
    x--;
    a[x] += y;
    val.emplace_back(a[x]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  auto get_id = [&](ll x) {
    return (int)(lower_bound(val.begin(), val.end(), x) - val.begin());
  };
  lazy_segtree<node, op, e, F, mapping, composition, id> seg((int)val.size());
  lazy_segtree<node, op, e, F, mapping, composition, id> num((int)val.size());
  for (int i = 0; i < (int)val.size(); ++i) {
    seg.set(i, {0, 1});
    num.set(i, {0, 1});
  }
  num.set(get_id(0), {n, 1});
  fill(a.begin(), a.end(), 0);
  for (auto &[x, y] : query) {
    ll l = a[x], r = a[x] + y;
    if (y == 0)
      continue;
    if (l > r)
      swap(l, r);
    int l_id = get_id(l), r_id = get_id(r);
    ans[x] += seg.get(get_id(a[x])).sum - cur[x];
    seg.apply(l_id, r_id, 1);
    ans[x] += num.prod(get_id(l) + 1, get_id(r) + 1).sum;
    // cout << num.prod(get_id(l) + 1, get_id(r) + 1).sum << "\n";
    if (a[x] == r)
      ans[x]--;
    num.apply(get_id(a[x]), -1);
    num.apply(get_id(a[x] + y), 1);
    a[x] += y;
    cur[x] = seg.get(get_id(a[x])).sum;
  }

  for (int x = 0; x < n; ++x) {
    ans[x] += seg.get(get_id(a[x])).sum - cur[x];
    cout << ans[x] << "\n";
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