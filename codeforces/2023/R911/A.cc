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
  string s;
  cin >> s;
  int cnt = 0;
  int ans = 0;
  bool flag = false;
  for (auto i : s) {
    if (i == '#') {
      ans += min(cnt, 2);
      cnt = 0;
    } else {
      cnt++;
      if (cnt >= 3) {
        flag = true;
      }
    }
  }
  ans += min(cnt, 2);
  if (flag) {
    cout << min(ans, 2) << "\n";
  } else {
    cout << ans << "\n";
  }
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