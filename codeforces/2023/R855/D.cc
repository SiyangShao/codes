#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using i64 = long long;
auto solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int ans = n - 1;
  for (int i = 1; i + 1 < n; ++i) {
    if (s[i + 1] == s[i - 1])
      ans--;
  }
  std::cout << ans << "\n";
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  while (_--) {
    solve();
  }
}