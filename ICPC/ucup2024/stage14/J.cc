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
node op(node l, node r) { return max(l, r); }
node e() { return 0; }
using F = ll;
node mapping(F f, node x) { return f + x; }
node composition(F f, F g) { return f + g; }
node id() { return 0; }
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> pos(n, vector<int>());
  vector<int> x(m), t(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> t[i];
    t[i]--;
    pos[t[i]].emplace_back(i);
  }
  lazy_segtree<node, op, e, F, mapping, composition, id> seg(m);
  ll non_renewable = 0;
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    if (!pos[i].empty()) {
      reverse(pos[i].begin(), pos[i].end());
      auto cur = *pos[i].rbegin();
      seg.apply(cur, m, a[i]);
      st.emplace(cur, a[i]);
    } else {
      non_renewable += a[i];
    }
  }
  ll pre = 0;
  for (int i = 0; i < m; ++i) {
    // check whether we could arrive here
    ll dis = x[i] - pre;
    int to_del = -1;
    if (seg.prod(0, m) < dis) {
      ll res = dis - seg.prod(0, m);
      if (res > non_renewable) {
        cout << pre + seg.prod(0, m) + non_renewable << endl;
        return;
      } else {
        non_renewable -= res;
      }
      to_del = m;
    } else {
      int l = 0, r = m - 1;
      int ans = m - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        auto cur = seg.prod(0, mid + 1);
        if (cur >= dis) {
          ans = min(ans, mid);
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      to_del = ans;
    }
    ll new_add = 0;
    while (!st.empty() && st.begin()->first < to_del) {
      auto [idx, _ ] = *st.begin();
      auto val = seg.get(idx);
      new_add += val;
      st.erase(st.begin());
      seg.apply(idx, m, -val);
    }
    dis -= new_add;
    if (to_del != m) {
      seg.apply(to_del, m, -dis);
    }
    auto lst = pos[t[i]].back();
    auto lst_val = seg.get(lst);
    seg.apply(lst, m, -lst_val);
    pos[t[i]].pop_back();
    if (!pos[t[i]].empty()) {
      auto cur = pos[t[i]].back();
      seg.apply(cur, m, a[t[i]]);
      st.emplace(cur, a[t[i]]);
    } else {
      non_renewable += a[t[i]];
    }
    pre = x[i];
  }
  cout << pre + seg.prod(0, m) + non_renewable << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
