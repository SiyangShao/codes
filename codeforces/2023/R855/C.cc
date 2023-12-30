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
  std::vector<i64> vec(n);
  for (auto &i : vec)
    std::cin >> i;
  i64 ans = 0;
  std::priority_queue<i64> Q;
  for (auto i : vec) {
    if (i != 0) {
      Q.emplace(i);
    } else {
      if (!Q.empty()) {
        ans += Q.top();
        Q.pop();
      }
    }
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