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
namespace fuzhi {
struct node {
  ll sum, len;
};
node op(node l, node r) { return node{l.sum + r.sum, l.len + r.len}; }
node e() { return node{0, 0}; }
using F = long long;
node mapping(F f, node x) {
  if (f == -1)
    return x;
  return node{f * x.len, x.len};
}
F composition(F f, F g) {
  if (f == -1)
    return g;
  return f;
} // f(g())
F id() { return F{-1}; }
} // namespace fuzhi
namespace mx {
struct node {
  ll val;
  int idl, idr;
};
node op(node l, node r) {
  if (l.val > r.val) {
    return l;
  } else if (r.val > l.val) {
    return r;
  } else {
    node tmp;
    tmp.val = l.val;
    tmp.idl = min(l.idl, r.idl);
    tmp.idr = max(l.idr, r.idr);
    return tmp;
  }
}
node e() { return {0, (int)1e6, (int)-1e6}; }
using F = long long;
node mapping(F f, node x) {
  if (f == -1)
    return x;
  x.val = f;
  return x;
}
F composition(F f, F g) {
  if (f == -1)
    return g;
  return f;
} // f(g())
F id() { return F{-1}; }
} // namespace mx
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;

  lazy_segtree<fuzhi::node, fuzhi::op, fuzhi::e, fuzhi::F, fuzhi::mapping,
               fuzhi::composition, fuzhi::id>
      seg(n);
  lazy_segtree<mx::node, mx::op, mx::e, mx::F, mx::mapping, mx::composition,
               mx::id>
      mxseg(n);
  ll sum = 0;
  vector<ll> lef(n), rig(n);
  for (int i = 0; i < n; ++i) {
    mxseg.set(i, {a[i], i, i});
    sum += a[i];
    if (i == 0)
      lef[i] = a[i];
    else
      lef[i] = max(a[i], lef[i - 1]);
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1)
      rig[i] = a[i];
    else
      rig[i] = max(a[i], rig[i + 1]);
  }
  for (int i = 0; i < n; ++i) {
    seg.set(i, {min(lef[i], rig[i]), 1});
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    ll v;
    cin >> x >> v;
    x--;
    sum += v;
    a[x] += v;
    mxseg.set(x, {a[x], x, x});
    auto cur = seg.get(x);
    if (cur.sum < a[x]) {
      seg.set(x, {a[x], 1});
      [&]() {
        // upd right
        if (x == n - 1)
          return;
        auto mxright = mxseg.prod(x + 1, n);
        if (mxright.val <= a[x]) {
          seg.apply(x + 1, mxright.idl, mxright.val);
          // cout<<mxright.idl<<" "<<x<<" "<<mxright.val<<" case1\n";
          return;
        }
        int l = x + 1, r = n - 1;
        int ans = r;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (mxseg.prod(x + 1, mid + 1).val > a[x]) {
            ans = min(ans, mid);
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
        seg.apply(x + 1, ans, a[x]);
        // cout << x + 1 << " " << ans << " " << a[x] << " case2\n";
      }();
      [&]() {
        // upd left
        if (x == 0)
          return;
        auto mxleft = mxseg.prod(0, x);
        if (mxleft.val <= a[x]) {
          seg.apply(mxleft.idr, x, mxleft.val);
          // cout<<mxleft.idr<<" "<<x<<" "<<mxleft.val<<" case1\n";
          return;
        }
        int l = 0, r = x - 1;
        int ans = l;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (mxseg.prod(mid, x).val > a[x]) {
            ans = max(ans, mid);
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        // cout << ans << endl;
        seg.apply(ans + 1, x, a[x]);
        // cout << ans + 1 << " " << x << " " << a[x] << " case2\n";
      }();
    }
    cout << seg.prod(0, n).sum - sum << "\n";
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