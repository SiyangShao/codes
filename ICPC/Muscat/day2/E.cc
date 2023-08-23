#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e18;
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
using node = ll;
node op(node l, node r) { return min(l, r); }
node e() { return inf; }
using F = long long;
node mapping(F f, node x) { return x + f; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
vector<ll> get_val(const int n, const ll C, string_view s,
                   const vector<ll> &v) {
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(n);
  vector<ll> cost(n, inf);
  int L = -1, R = -1;
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] == s[n - i - 1])
      continue;
    L = i;
    break;
  }
  for (int i = n / 2 - 1; i >= 0; --i) {
    if (s[i] == s[n - i - 1])
      continue;
    R = i;
    break;
  }
  dbg(L, R);
  if (L == -1) {
    fill(cost.begin(), cost.end(), 0);
    return cost;
  }
  {
    ll tmp = 0;
    for (int i = n - R - 1; i <= n - L - 1; ++i) {
      if (s[i] != s[n - i - 1]) {
        tmp += v[i];
      }
      seg.set(i, tmp);
      tmp += C;
    }
    cost[n - R - 1] = tmp - C;
  }
  for (int i = n - R - 1 - 1; i >= 0; --i) {
    seg.apply(i + 1, n, C);
    if (s[i] == s[n - i - 1]) {
      seg.set(i, 0);
    } else {
      seg.set(i, 0);
      seg.apply(i, n, v[i]);
      if (i < n / 2) {
        if (v[i] < v[n - i - 1]) {
          seg.apply(n - i - 1, n, -v[n - i - 1]);
        } else {
          seg.apply(n - i - 1, n, -v[i]);
        }
      }
    }
    if (i > L) {
      cost[i] = seg.prod(n - L - 1, n);
    } else {
      cost[i] = seg.prod(R, n);
    }
  }

  return cost;
}
vector<ll> cal_dp(ll n, ll C, const vector<ll> &cost) {
  vector<ll> dp(n, inf);
  function<void(ll, ll, ll, ll)> dfs = [&](ll l, ll r, ll L, ll R) {
    if (l > r || L > R)
      return;
    ll mid = (l + r) / 2;
    ll pos = L;
    for (ll i = L; i <= min(R, mid); ++i) {
      if (dp[mid] > cost[i] + C * abs(mid - i)) {
        dp[mid] = cost[i] + C * abs(mid - i);
        pos = i;
      }
    }
    dfs(l, mid - 1, L, pos);
    dfs(mid + 1, r, pos, R);
  };
  dfs(0, n - 1, 0, n - 1);
  return dp;
}
vector<ll> dp(int n, ll C, string_view s, vector<ll> &v) {
  auto cost = get_val(n, C, s, v);
  dbg(cost);
  return cal_dp(n, C, cost);
}
auto solve() {
  int n;
  ll C;
  cin >> n >> C;
  string s;
  cin >> s;
  vector<ll> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  auto x = dp(n, C, s, v);
  dbg(x);
  reverse(s.begin(), s.end());
  reverse(v.begin(), v.end());
  auto y = dp(n, C, s, v);
  reverse(y.begin(), y.end());
  for (int i = 0; i < n; ++i) {
    cout << min(x[i], y[i]) << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}