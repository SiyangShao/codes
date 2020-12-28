#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  ll a, b, r;
  cin >> a >> b >> r;
  if (a < b)
    swap(a, b);
  bool flag = false;
  ll ans = 0;
  for (ll i = 62; i >= 0; --i) {
    ll x = (a >> i) & 1, y = (b >> i) & 1;
    if (x == y)
      continue;
    if (x) {
      if (!flag) {
        ans += 1LL << i;
        flag = true;
        continue;
      }
      if (r >= (1LL << i)) {
        r -= 1LL << i;
        ans -= 1LL << i;
      } else {
        ans += 1LL << i;
      }
    } else {
      ans -= 1LL << i;
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}