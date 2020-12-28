#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using i128 = __int128;
constexpr ll HALF = 1LL << 63;
constexpr ll MXHALF = 1LL << 31;
auto solve() {
  int n;
  cin >> n;
  vector<pair<i128, i128>> a(n);
  map<i128, ll> mp;
  ll ans = 0;
  mp[0] = 1;
  i128 res = 0;
  i128 one = 1;
  one = one * HALF;
  one = one * MXHALF;
  for (auto &[l, r] : a) {
    ll x, y;
    cin >> x >> y;
    ll gg = gcd(x, y);
    x /= gg, y /= gg;
    l = x, r = y;
    l = l % r;
    l = l * HALF;
    l = l * MXHALF;
    l /= r;
    res = res + l;
    res = res % one;
    for (i128 dif = res - 10; dif <= res + 10; ++dif) {
      i128 tmp = dif;
      tmp = (tmp + one) % one;
      auto it = mp.find(tmp);
      if (it != mp.end())
        ans += it->second;
    }
    mp[res]++;
  }
  cout << ans << "\n";
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