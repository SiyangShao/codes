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
  vector<int> a(n);
  for (auto &i : a)
    cin >> i, i--;
  vector<ll> pri(n, 0);
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(n);
  for (int i = 0; i < n; ++i) {
    seg.set(i, {0, 1});
  }
  ll same = 0, odd = 0, even = 0, tot = 0;
  for (int i = 0; i < n; ++i) {
    pri[a[i]] += seg.prod(a[i], n).sum;
    tot += pri[a[i]];
    seg.set(a[i], {1, 1});
  }
  tot = tot % 2;
  for (int i = 0; i < n; ++i) {
    seg.set(i, {0, 1});
  }
  for (int i = n - 1; i >= 0; --i) {
    pri[a[i]] += seg.prod(0, a[i]).sum;
    seg.set(a[i], {1, 1});
  }
  for (int i = 0; i < n; ++i) {
    // cout<<pri[i]<<" ";
    if (a[i] == i)
      same++;
    pri[i] %= 2;
    // cout<<pri[i]<<" ";
    if (pri[i] == 0)
      even++;
    else
      odd++;
  }
  // cout<<"\n";
  function<void(int, int, int, int)> update = [&](int l, int u, int v,
                                                  int len) {
    if (u == l) {
      same--;
    }
    a[l] = v;
    if (v == l) {
      same++;
    }
    if (len % 2 == 1) {
      pri[u] ^= 1;
      if (pri[u] % 2 == 1) {
        even--, odd++;
      } else {
        even++, odd--;
      }
    }
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int u = a[l], v = a[r];
    update(l, u, v, abs(r - l));
    update(r, v, u, abs(r - l));
    // cout << odd << " " << even << " ";
    tot ^= 1;
    if (same == n) {
      cout << "-1\n";
    } else {
      if (tot % 2 == 1) {
        cout << n << "\n";
      } else {
        if (odd > 0) {
          cout << n - 1 << "\n";
        } else {
          cout << n - 2 << "\n";
        }
      }
    }
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