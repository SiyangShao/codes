#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line &o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end())
      return x->p = inf, 0;
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z))
      z = erase(z);
    if (x != begin() && isect(--x, y))
      isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

void solve() {
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  vector<ll> h(n);
  for (auto &e : h)
    cin >> e;
  vector<vector<ll>> g(n);
  for (ll i = 1; i <= m; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }

  vector<ll> ds(n, 0x3f3f3f3f3f3f3f3fll), dt(n, 0x3f3f3f3f3f3f3f3fll);
  auto dijkstra = [&](vector<ll> &d, ll s) {
    d[s] = 0;
    set<pair<ll, ll>> q;
    q.emplace(d[s], s);
    while (!q.empty()) {
      auto [_, tx] = *q.begin();
      q.erase(q.begin());
      for (auto e : g[tx]) {
        ll dh = h[e] - h[tx];
        if (d[e] > d[tx] + dh * dh) {
          q.erase(make_pair(d[e], e));
          d[e] = d[tx] + dh * dh;
          q.emplace(d[e], e);
        }
      }
    }
  };
  dijkstra(ds, s), dijkstra(dt, t);
  assert(ds[t] == dt[s]);

  ll ans = 2 * ds[t];
  for (ll i = 0; i < n; ++i) {
    if (i == s)
      for (auto e : g[s])
        ans = min(ans, 2 * dt[e]);
    else if (i == t)
      for (auto e : g[t])
        ans = min(ans, 2 * ds[e]);
    else {
      LineContainer lc;
      LineContainer lc2;
      for (auto e1 : g[i]) {
        if (!lc.empty()) {
          ll min_e2 = -lc.query(h[e1]);
          ans = min(ans, min_e2 + h[e1] * h[e1] + 2 * ds[e1]);

          ll min_alt = -lc2.query(h[e1]);
          ans = min(ans, min_alt + h[e1] * h[e1] + 2 * dt[e1]);
        }
        lc.add(2 * h[e1], -h[e1] * h[e1] - 2 * dt[e1]);
        lc2.add(2 * h[e1], -h[e1] * h[e1] - 2 * ds[e1]);
      }
    }
  }
  if (ans % 2 == 1)
    cout << ans / 2 << ".5" << '\n';
  else
    cout << ans / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  ll T = 1;
  // cin >> T;
  while (T--)
    solve();
  return 0;
}