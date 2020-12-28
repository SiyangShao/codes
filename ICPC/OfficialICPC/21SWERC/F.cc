#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct SegmentTreeMx {
  struct segt {
    ll l, r;
    pair<ll, ll> ans;
  };
  vector<segt> T;
  vector<pair<ll, ll>> a;
  SegmentTreeMx(ll n) { // don't forget to call build.
    T.resize(n << 2);
    a.resize(n + 1);
  }

  segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r;
    res.ans = max(l.ans, r.ans); // TODO
    return res;
  }

  void build(ll l, ll r, ll o = 1) {
    T[o].l = l, T[o].r = r;
    if (l == r)
      T[o].ans = a[l]; // TODO
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

  void update(ll tx, pair<ll, ll> nx, ll o = 1) { // singly update
    if (T[o].l == T[o].r) {
      T[o].ans = nx;
    } // TODO
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
struct SegmentTreeMi {
  struct segt {
    ll l, r;
    pair<ll, ll> ans;
  };
  vector<segt> T;
  vector<pair<ll, ll>> a;
  SegmentTreeMi(ll n) { // don't forget to call build.
    T.resize(n << 2);
    a.resize(n + 1);
  }
  segt combine(segt l, segt r) {
    segt res;
    res.l = l.l, res.r = r.r;
    res.ans = min(l.ans, r.ans); // TODO
    return res;
  }

  void build(ll l, ll r, ll o = 1) {
    T[o].l = l, T[o].r = r;
    if (l == r)
      T[o].ans = a[l]; // TODO
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

  void update(ll tx, pair<ll, ll> nx, ll o = 1) { // singly update
    if (T[o].l == T[o].r) {
      T[o].ans = nx;
    } // TODO
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
constexpr ll N = 200010;
constexpr ll inf = 1e16;
SegmentTreeMi mi(N);
SegmentTreeMx mx(N);
auto solve() {
  ll n, s, t;
  cin >> n >> s >> t;
  vector<ll> p(n + 1);
  mi.a.resize(n + 1);
  mx.a.resize(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> p[i];
    mi.a[i] = {i - p[i], i};
    mx.a[i] = {i + p[i], i};
    if (i == s) {
      mi.a[i] = {inf, -1};
      mx.a[i] = {-inf, -1};
    }
  }
  mi.build(1, n);
  mx.build(1, n);
  queue<int> Q;
  vector<ll> dis(n + 1, inf);
  dis[s] = 0;
  Q.emplace(s);
  while (!Q.empty()) {
    auto u = Q.front();
    // cout<<u<<"\n";
    Q.pop();
    ll R = u + p[u], L = u + 1;
    R = min(R, n), L = min(L, n);
    if (R > u)
      while (true) {
        auto tp = mi.query(L, R);
        if (tp.ans.second == -1 || tp.ans.first > u) {
          break;
        }
        auto v = tp.ans.second;
        dis[v] = dis[u] + 1;
        Q.emplace(v);
        mi.update(v, {inf, -1});
        mx.update(v, {-inf, -1});
      }
    R = u - 1, L = u - p[u];
    R = max(R, 1LL), L = max(L, 1LL);
    if (L < u)
      while (true) {
        auto tp = mx.query(L, R);
        if (tp.ans.second == -1 || tp.ans.first < u) {
          break;
        }
        auto v = tp.ans.second;
        dis[v] = dis[u] + 1;
        Q.emplace(v);
        mi.update(v, {inf, -1});
        mx.update(v, {-inf, -1});
      }
  }
  cout << dis[t] << "\n";
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