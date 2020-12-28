#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using i64 = long long;
auto solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;
  std::vector<int> upper(26, 0), lower(26, 0);
  for (auto i : s) {
    if (i >= 'A' && i <= 'Z') {
      upper[i - 'A']++;
    } else {
      lower[i - 'a']++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    auto tmp = std::min(upper[i], lower[i]);
    ans += tmp;
    upper[i] -= tmp, lower[i] -= tmp;
    tmp = std::max(upper[i], lower[i]);
    ans += std::min(tmp / 2, k);
    if (k >= tmp / 2) {
      k -= tmp / 2;
    } else {
      k = 0;
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