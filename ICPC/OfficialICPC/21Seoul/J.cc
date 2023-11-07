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

  vector<pair<int, int>> ans;
  function<void(int, int, int, int)> cal = [&](int x, int y, int a, int b) {
    cout << x << " " << y << endl << "\n";
    if (x == 0 || y == 0)
      return;
    if (x > y) {
      // ans.emplace_back(a, b);
      x -= y;
      y *= 2;
    } else {
      y -= x;
      x *= 2;
      // ans.emplace_back(b, a);
    }
    cal(x, y, a, b);
  };
  int x, y, z;
  cin >> x >> y >> z;
  if (x % 2 == y % 2) {
    cal(x, y, 1, 2);
  } else if (x % 2 == z % 2) {
    cal(x, z, 1, 3);
  } else {
    cal(y, z, 2, 3);
  }
  cout << ans.size() << "\n";
  for (auto [l, r] : ans) {
    cout << l << " " << r << "\n";
  }
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