#include <bits/stdc++.h>
using namespace std;
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
  int sum, len;
};
node op(node l, node r) { return node{min(l.sum, r.sum), l.len + r.len}; }
node e() { return node{0, 0}; }
using F = int;
node mapping(F f, node x) { return node{x.sum + f, x.len}; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto &i : s) {
    cin >> i;
  }
  map<string, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; ++i) {
    string t = s[i];
    string num = t.substr(1, t.size() - 1);
    if (t[0] == 's') {
      mp[num].emplace_back(i, 1);
    } else {
      mp[num].emplace_back(i, -1);
    }
  }
  lazy_segtree<node, op, e, F, mapping, composition, id> ans_seg(n);
  for (int i = 0; i < n; ++i) {
    ans_seg.set(i, node{0, 1});
  }
  for (auto &[_, vec] : mp) {
    int cnt = 0;
    for (auto [pos, i] : vec) {
      cnt += i;
    }
    if (cnt != 0)
      continue;
    int m = (int)vec.size();
    lazy_segtree<node, op, e, F, mapping, composition, id> seg(m);
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      cnt += vec[i].second;
      // cout << cnt << " ";
      seg.set(i, node{cnt, 1});
    }
    // cout << "\n";
    for (int i = 0; i < m; ++i) {
      if (seg.prod(0, m).sum >= 0) {
        int prev = (i + m - 1) % m;
        int prev_pos = (vec[prev].first + 1) % n;
        int pos = (vec[i].first + 1) % n;
        if (prev_pos < pos) {
          ans_seg.apply(prev_pos, pos, 1);
        } else {
          ans_seg.apply(prev_pos, n, 1);
          ans_seg.apply(0, pos, 1);
        }
      }
      seg.apply(0, m, -vec[i].second);
      int j = (i + m - 1) % m;
      int pre_sum = seg.get(j).sum;
      seg.apply(i, i + 1, vec[i].second + pre_sum);
      // seg.apply(i, i + 1, vec[i].second);
      // for (int j = 0; j < m; ++j) {
      //   cout << seg.get(j).sum << " ";
      // }
      // cout << "\n";
    }
    // cout << "!!!\n";
  }
  int ans = 0, pos = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = ans_seg.get(i).sum;
    if (cnt > ans)
      ans = cnt, pos = i;
  }
  cout << pos + 1 << " " << ans << "\n";
}