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
  ll n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n << "\n";
    return;
  }
  ll l = 1, r = 2e9;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (mid * (mid + 1) / 2 >= n - m) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l + m << "\n";
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