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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  ll x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      x += a[i];
    else
      y += a[i];
  }
  ll u = 0, v = 0;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      x -= a[i];
    else
      y -= a[i];
    if (x + u == y + v) {
      ans++;
    }
    if (i % 2 == 0)
      v += a[i];
    else
      u += a[i];
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