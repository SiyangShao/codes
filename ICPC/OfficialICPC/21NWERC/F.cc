#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cross(pair<ll, ll> x, pair<ll, ll> y) {
  return x.first * y.second - y.first * x.second;
}
ll side(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z) {
  return cross({y.first - x.first, y.second - x.second},
               {z.first - x.first, z.second - x.second});
}
pair<ll, ll> s, e;
int discrete(vector<pair<ll, ll>> &vec, bool flg) {
  int n = (int)vec.size();
  auto nxt = vec;
  vector<ll> x(vec.size()), y(vec.size());
  iota(x.begin(), x.end(), 0);
  iota(y.begin(), y.end(), 0);
  sort(x.begin(), x.end(), [&](auto L, auto R) {
    auto l = vec[L], r = vec[R];
    if (flg)
      return side(s, l, r) < 0;
    else
      return side(s, l, r) > 0;
  });
  sort(y.begin(), y.end(), [&](auto L, auto R) {
    auto l = vec[L], r = vec[R];
    if (flg)
      return side(e, l, r) > 0;
    else
      return side(e, l, r) < 0;
  });
  for (int i = 0; i < n; ++i) {
    nxt[x[i]].first = i + 1;
    if (i > 0 && side(s, vec[x[i]], vec[x[i - 1]]) == 0) {
      nxt[x[i]].first = nxt[x[i - 1]].first;
    }
    nxt[y[i]].second = i + 1;
    if (i > 0 && side(s, vec[y[i]], vec[y[i - 1]]) == 0) {
      nxt[y[i]].second = nxt[y[i - 1]].second;
    }
  }
  vec = move(nxt);
  return n;
}
struct SegmentTree {
  struct segt {
    ll l, r;
    ll ans;
  };
  vector<segt> T;

  SegmentTree(ll n) { // don't forget to call build.
    T.resize(n << 2);
  }

  segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r;
    res.ans = l.ans + r.ans; // TODO
    return res;
  }

  void build(ll l, ll r, ll o = 1) {
    T[o].l = l, T[o].r = r;
    if (l == r)
      T[o].ans = 0; // TODO
    else {
      ll m = (l + r) >> 1;
      build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
      T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
  }

  segt query(ll l, ll r, ll o = 1) {
    assert(l <= r);
    if (T[o].l == l && T[o].r == r)
      return T[o];
    else {
      ll m = (T[o].l + T[o].r) >> 1;
      if (r <= m)
        return query(l, r, o << 1);
      else if (l >= m + 1)
        return query(l, r, o << 1 | 1);
      return combine(query(l, m, o << 1), query(m + 1, r, o << 1 | 1));
    }
  }

  void update(ll tx, ll nx, ll o = 1) { // singly update
    if (T[o].l == T[o].r)               // TODO
      T[o].ans++;
    else {
      ll m = (T[o].l + T[o].r) >> 1;
      if (tx <= m)
        update(tx, nx, o << 1);
      else
        update(tx, nx, o << 1 | 1);
      T[o] = combine(T[o << 1], T[o << 1 | 1]);
    }
  }
};
ll solve(vector<pair<ll, ll>> &vec, int mx) {
  SegmentTree a(mx);
  a.build(1, mx);
  sort(vec.begin(), vec.end());
  ll ans = 0;
  for (auto &[l, r] : vec) {
    ans += a.query(1, r).ans;
    a.update(r, 1);
  }
  return ans;
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> s.first >> s.second >> e.first >> e.second;
  if (s.first > e.first) {
    swap(s, e);
  }
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (auto &[x, y] : p) {
    cin >> x >> y;
  }
  vector<pair<ll, ll>> above, below, zero;
  for (auto i : p) {
    if (side(s, e, i) == 0) {
      zero.emplace_back(i);
    } else if (side(s, e, i) > 0) {
      above.emplace_back(i);
    } else {
      below.emplace_back(i);
    }
  }
  ll ans = 0;
  sort(zero.begin(), zero.end());
  if (s.first == e.first) {
    ll neg = 0, pos = 0;
    for (auto [x, y] : zero) {
      if (y <= min(s.second, e.second))
        neg++;
      else
        pos++;
    }
    ans += neg * (neg - 1) / 2;
    ans += pos * (pos - 1) / 2;
  } else {
    ll neg = 0, pos = 0;
    for (auto [x, y] : zero) {
      if (x <= min(s.first, e.first))
        neg++;
      else
        pos++;
    }
    ans += neg * (neg - 1) / 2;
    ans += pos * (pos - 1) / 2;
  }
  int mx;
  mx = discrete(above, true);
  if (mx)
    ans += solve(above, mx);
  cout << ans << "\n";
  mx = discrete(below, true);
  if (mx)
    ans += solve(below, mx);
  cout << ans << "\n";
}