#include <bits/stdc++.h>
#include <iomanip>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> val(n);
  for (auto &i : val)
    cin >> i;
  vector<pair<ld, ld>> cst(n), scale(n);
  for (int t = 0; t < n; ++t) {
    for (int s = 0; s < n; ++s) {
      ld COS = cos(-(ld)t * s * M_PI * 2.0 / n);
      ld SIN = sin(-(ld)t * s * M_PI * 2.0 / n);
      if (s != k) {
        cst[t].first += COS * val[s];
        cst[t].second += SIN * val[s];
      } else {
        scale[t] = {COS, SIN};
      }
    }
  }
  function<ld(ll)> f = [&](ll x) {
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
      ld a = cst[i].first + scale[i].first * x;
      ld b = cst[i].second + scale[i].second * x;
      ans = max(ans, a * a + b * b);
    }
    return sqrt(ans);
  };
  function<double()> search = [&]() {
    ll l = -1e7, r = 1e7;
    ld ans = 1e18;
    for (int i = 0; i < 1000; ++i) {
      ll m1 = (2 * l + r) / 3;
      ll m2 = (l + 2 * r) / 3;
      if (m2 - m1 <= 5000) {
        for (ll j = m1-5000; j <= m2+5000; ++j) {
          ans = min(ans, f(j));
        }
        return ans;
      }
      if (f(m1) >= f(m2)) {
        l = m1;
      } else {
        r = m2;
      }
    }
    return f(l);
  };
  cout << fixed << setprecision(12);
  cout << search() << "\n";
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