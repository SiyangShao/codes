#include <bits/stdc++.h>
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) __VA_ARGS__
#endif
using namespace std;
using ll = int;
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
using F = ll;
node mapping(F f, node x) { return node{x.sum + f * x.len, x.len}; }
F composition(F f, F g) { return F{f + g}; } // f(g())
F id() { return F{0}; }
namespace special {
using pii = pair<int, int>;
struct node {
  ll dp;
  ll p1, p2, sum;
};
node op(node l, node r) {
  return {l.dp + r.dp, l.p1 + r.p1, l.p2 + r.p2, l.sum + r.sum};
}
node e() { return node{0, 0, 0, 0}; }
using F = ll;
node mapping(F f, node x) {
  if (f == -1)
    return x;
  if (f == 0)
    x.sum = x.p1 + x.dp;
  if (f == 1)
    x.sum = x.p2 + x.dp;
  if (f == 2)
    x.sum = 0;
  return x;
}
F composition(F f, F g) {
  if (f == -1)
    return g;
  return f;
}
F id() { return -1; }
}; // namespace special
auto solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> vec;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    vec.emplace_back(l, r, i);
  }
  sort(vec.begin(), vec.end());
  vector<vector<tuple<int, int, int>>> seg;
  {
    vector<tuple<int, int, int>> tmp;
    tmp.emplace_back(vec[0]);
    int r = get<1>(vec[0]);
    for (int i = 1; i < n; ++i) {
      if (get<0>(vec[i]) > r) {
        seg.emplace_back(tmp);
        dbg(tmp);
        tmp.clear();
      }
      r = max(r, get<1>(vec[i]));
      tmp.emplace_back(vec[i]);
    }
    dbg(tmp);
    seg.emplace_back(tmp);
  }
  vector<int> in(n);
  auto cal_in = [&](auto &interval) {
    vector<pair<int, int>> x;
    int m = (int)interval.size();
    lazy_segtree<node, op, e, F, mapping, composition, id> segment(m);
    for (int i = 0; i < m; ++i) {
      segment.set(i, {0, 1});
    }
    for (auto &[a, b, id] : interval) {
      x.emplace_back(a, id);
      x.emplace_back(b, id + n);
    }
    sort(x.begin(), x.end());
    int inside = 0;
    for (auto &[a, id] : x) {
      if (id < n) {
        in[id] = inside;
        inside++;
        segment.set(in[id], {1, 1});
      } else {
        int ini = in[id - n];
        id -= n;
        in[id] = inside - ini - segment.prod(ini, m).sum;
        segment.set(ini, {0, 1});
      }
    }
  };
  vector<int> out(n, 0);
  auto cal_out = [&](auto &interval) {
    vector<pair<int, int>> x;
    int m = (int)interval.size();
    lazy_segtree<node, op, e, F, mapping, composition, id> segment(m);
    for (int i = 0; i < m; ++i) {
      segment.set(i, {0, 1});
    }
    for (auto &[a, b, id] : interval) {
      x.emplace_back(a, id);
      x.emplace_back(b, id + n);
    }
    sort(x.begin(), x.end());
    int inside = 0;
    for (auto &[a, id] : x) {
      if (id < n) {
        out[id] = inside;
        inside++;
        segment.set(out[id], {1, 1});
      } else {
        int ini = out[id - n];
        id -= n;
        out[id] = segment.prod(0, ini).sum;
        segment.set(ini, {0, 1});
      }
    }
  };
  vector<vector<int>> E(n);
  vector<int> dp(n), siz(n);
  auto cal_right = [&](auto &interval, auto &r) {
    sort(interval.begin(), interval.end(),
         [](auto x, auto y) { return get<1>(x) < get<1>(y); });
    int m = (int)interval.size();
    int root = -1;
    {
      vector<tuple<int, int, int>> x;
      for (auto &[a, b, id] : interval) {
        x.emplace_back(a, id, b);
        E[id].clear();
        dp[id] = 0;
        x.emplace_back(b, id, a);
      }
      sort(x.begin(), x.end());
      dbg(x);
      set<pair<int, int>> st;
      for (auto &[a, id, b] : x) {
        if (a < b) {
          st.emplace(b, id);
        } else {
          auto [v, vid] = *st.rbegin();
          if (vid == id)
            root = id;
          else
            E[vid].emplace_back(id);
          st.erase({a, id});
        }
      }
    }
    dbg(E);
    function<void(int)> dfs = [&](int u) {
      dp[u] = 0, siz[u] = 1;
      for (auto v : E[u]) {
        dfs(v);
        dp[u] += dp[v] + siz[v];
        siz[u] += siz[v];
      }
    };
    assert(root == get<2>(*interval.rbegin()));
    dfs(root);
    dbg(dp, siz);
    lazy_segtree<special::node, special::op, special::e, special::F,
                 special::mapping, special::composition, special::id>
        segment(m);

    vector<pair<int, int>> x;
    for (int i = 0; i < m; ++i) {
      auto id = get<2>(interval[i]);
      x.emplace_back(get<1>(interval[i]), id);
      segment.set(i, {dp[id], siz[id], siz[id] * 2,
                      0}); // F = 0 is son, 1 is neighbor, 2 is others
    }
    dbg(x);
    for (int i = m - 1; i > 0; --i) {
      auto [a, b, id] = interval[i];
      auto pos = lower_bound(x.begin(), x.end(), pair<int, int>{a, 0});
      int vv = (int)(pos - x.begin());
      dbg(interval[i], pos->second, vv);
      segment.apply(i, m, 2);
      if (vv < i)
        segment.apply(vv, i, 0);
      auto cur = segment.prod(0, m);
      r[id] = dbg(cur.sum);
      segment.apply(vv, i, 1);
      segment.apply(i, m, 2);
    }
    dbg(r);
  };
  vector<int> r(n, 0), l(n, 0);
  for (auto &interval : seg) {
    dbg(interval);
    cal_in(interval);
    cal_out(interval);
    cal_right(interval, r);
    auto nxtInterval = interval;
    for (int i = 0; i < (int)interval.size(); ++i) {
      auto [a, b, c] = interval[i];
      nxtInterval[i] = {n * 2 - b, n * 2 - a, c};
    }
    dbg(nxtInterval);
    cal_right(nxtInterval, l);
  }
  dbg(l, r, in, out);
  for (int i = 0; i < n; ++i) {
    cout << r[i] + l[i] - in[i] + out[i] << "\n";
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
