#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using ll = long long;
auto solve() {
  int l, r;
  cin >> l >> r;
  function<int(int)> cal_dif = [&](int x) {
    int mx = 0, mi = 9;
    while (x) {
      mx = max(mx, x % 10);
      mi = min(mi, x % 10);
      x /= 10;
    }
    return mx - mi;
  };
  int dif = 0, ans = 0;
  for (int i = l; i <= min(r, l + 100); ++i) {
    if (cal_dif(i) >= dif) {
      dif = cal_dif(i);
      ans = i;
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