#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll check(ll x) {
  ll ans = 0;
  while (x) {
    ans = max(ans, x % 10);
    x /= 10;
  }
  return ans;
}
auto solve() {
  ll la, ra, lb, rb;
  cin >> la >> ra >> lb >> rb;
  if (abs(ra - la) >= 10 || abs(rb - lb) >= 10) {
    cout << "9\n";
    return;
  }
  ll ans = 0;
  for (ll i = la; i <= ra; ++i) {
    for (ll j = lb; j <= rb; ++j) {
      ans = max(ans, check(i + j));
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