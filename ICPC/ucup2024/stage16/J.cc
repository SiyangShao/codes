#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
public:
  lazy_segtree() : lazy_segtree(0) {};
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
constexpr node inf = 0;
node op(node l, node r) { return max(l, r); }
node e() { return inf; }
using F = long long;
node mapping(F f, node x) { return f + x; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> f(n);
  for (auto &i : f) {
    cin >> i;
    i--;
  }
  sort(f.begin(), f.end());
  auto contains = [&](int i) {
    auto it = lower_bound(f.begin(), f.end(), i);
    if (it != f.end() && *it == i)
      return true;
    return false;
  };
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(k);
  vector<int> contri(k, 0);
  vector<vector<int>> E(k);
  int base = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a < b) {
      swap(a, b);
    }
    if (contains(a) && contains(b)) {
      base++;
    } else if (a == b) {
      contri[a]++;
    } else if (contains(a)) {
      contri[b]++;
    } else if (contains(b)) {
      contri[a]++;
    } else {
      E[a].emplace_back(b);
      E[b].emplace_back(a);
    }
  }
  ll ans = base;
  for (int i = 0; i < k; i++) {
    seg.set(i, contri[i]);
  }
  for (int i = 0; i < k; i++) {
    // choose i as first
    // remove i first
    seg.set(i, 0);
    ll cnt = base + contri[i];
    for (auto j : E[i]) {
      seg.apply(j, 1);
    }
    cnt += seg.prod(0, k);
    ans = max(ans, cnt);
    for (auto j : E[i]) {
      seg.apply(j, -1);
    }
    seg.set(i, contri[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
