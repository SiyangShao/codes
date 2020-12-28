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
};
using node = ll;
constexpr ll inf = 1e16;
node op(node l, node r) { return max(l, r); }
node op2(node l, node r) { return min(l, r); }
node e() { return -inf; }
node e2() { return inf; }
using F = long long;
node mapping(F f, node x) { return f + x; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  lazy_segtree<node, op, e, F, mapping, composition, id> seg_mx(a);
  lazy_segtree<node, op2, e2, F, mapping, composition, id> seg_mi(a);

  ll ans_mx = 0, ans_mi = 0;
  for (int i = 0; i < n; ++i) {
    ll val = a[i];
    function<bool(ll)> rig = [=](ll x) { return x <= val; };
    function<bool(ll)> lef = [=](ll x) { return x < val; };
    int rig_pos = seg_mx.max_right(i, rig);
    int lef_pos = seg_mx.min_left(i, lef);
    ans_mx += val * (ll)(rig_pos - i) * (ll)(i - lef_pos + 1);
    // cout << lef_pos << " " << rig_pos << ", ";
    function<bool(ll)> rig_mi = [=](ll x) { return x >= val; };
    function<bool(ll)> lef_mi = [=](ll x) { return x > val; };
    rig_pos = seg_mi.max_right(i, rig_mi);
    lef_pos = seg_mi.min_left(i, lef_mi);
    // cout << lef_pos << " " << rig_pos << "\n";
    ans_mi += val * (ll)(rig_pos - i) * (ll)(i - lef_pos + 1);
    // ans_mi += val * (rig_pos - lef_pos);
  }
  auto add = [&](int i) {
    function<bool(ll)> rig = [&](ll x) { return x <= a[i]; };
    function<bool(ll)> lef = [&](ll x) { return x < a[i]; };
    int r = seg_mx.max_right(i, rig);
    int l = seg_mx.min_left(i, lef);
    seg_mx.apply(i, 1);
    a[i]++;
    // int nr = seg_mx.max_right(i, rig);
    int nl = seg_mx.min_left(i, lef);
    // ans_mx += (ll)(r - nl);
    ans_mx += (ll)(r - i) * (ll)(i - nl + 1);
    a[i]--;
    // cout << lef_pos << " " << rig_pos << ", ";
    function<bool(ll)> rig_mi = [&](ll x) { return x >= a[i]; };
    function<bool(ll)> lef_mi = [&](ll x) { return x > a[i]; };
    r = seg_mi.max_right(i, rig_mi);
    l = seg_mi.min_left(i, lef_mi);
    a[i]++;
    seg_mi.apply(i, 1);
    int nr = seg_mi.max_right(i, rig_mi);
    // ans_mi += (nr - l);
    ans_mi += (ll)(nr - i) * (ll)(i - l + 1);
  };
  auto del = [&](int i) {
    function<bool(ll)> rig = [&](ll x) { return x <= a[i]; };
    function<bool(ll)> lef = [&](ll x) { return x < a[i]; };
    int r = seg_mx.max_right(i, rig);
    int l = seg_mx.min_left(i, lef);
    // cout << "MAX: \n";
    // cout << "PREV: ";
    // cout << l << " " << r << "\n";
    seg_mx.apply(i, -1);
    a[i]--;
    // int nl = seg_mx.min_left(i, lef);
    int nr = seg_mx.max_right(i, rig);
    // cout << "CUR: ";
    // cout << nl << " " << nr << "\n";

    ans_mx -= (ll)(nr - i) * (ll)(i - l + 1);
    // ans_mx -= (nr - l);
    a[i]++;
    // cout << "MIN: \n";
    // cout << lef_pos << " " << rig_pos << ", ";
    function<bool(ll)> rig_mi = [&](ll x) { return x >= a[i]; };
    function<bool(ll)> lef_mi = [&](ll x) { return x > a[i]; };
    r = seg_mi.max_right(i, rig_mi);
    l = seg_mi.min_left(i, lef_mi);
    a[i]--;
    // cout << "PREV: ";
    // cout << l << " " << r << "\n";
    // cout << lef_pos << " " << rig_pos << "\n";
    seg_mi.apply(i, -1);
    int nl = seg_mi.min_left(i, lef_mi);
    // nr = seg_mi.max_right(i, rig_mi);
    // cout << "CUR: ";
    // cout << nl << " " << nr << "\n";
    // ans_mi -= (r - nl);
    // cout << (ll)(r - i) * (ll)(i - nl + 1) << "\n";
    ans_mi -= (ll)(r - i) * (ll)(i - nl + 1);
  };
  while (q--) {
    string op;
    cin >> op;
    int id;
    cin >> id;
    id--;
    // cout << "OPOPOP\n";
    // cout << ans_mx << " " << ans_mi << "\n";
    if (op == "+") {
      add(id);
    } else {
      del(id);
    }
    // cout << ans_mx << " " << ans_mi << " ";
    cout << ans_mx - ans_mi << "\n";
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