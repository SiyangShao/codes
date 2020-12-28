#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct fwt {
  vector<ll> a;
  int _n;
  fwt(int n) : a(n), _n(n){};
  void upd(ll p, ll x) {
    p++;
    while (p <= _n) {
      a[p - 1] = max(a[p - 1], x);
      p += p & -p;
    }
  }
  auto get(ll p) {
    p++;
    ll res = 0;
    while (p > 0) {
      res = max(res, a[p - 1]);
      p -= p & -p;
    }
    return res;
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> p[i].second;
  }
  sort(p.begin(), p.end());
  auto f = fwt(50010);
  ll ans = 0, res = 0;
  for (auto [l, r] : p) {
    ans += max(l, r);
    ll cnt = min(l, r) + f.get(r);
    res = max(res, cnt);
    f.upd(r, cnt);
  }
  cout << ans + res << '\n';
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