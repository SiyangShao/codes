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
  ll a, b;
  cin >> a >> b;
  ll ans = a + b;
  for (ll i = 1; i <= max(a, b); ++i) {
    if (i - 1 + (a + i - 1) / i + (b + i - 1) / i <= ans) {
      ans = i - 1 + (a + i - 1) / i + (b + i - 1) / i;
    } else {
      break;
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