#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using i64 = long long;
constexpr int N = 26;
constexpr int MSK = (1 << N) - 1;
auto solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> mp(n);
  std::vector<std::bitset<N>> contain(n);
  std::vector<int> dp(n);
  for (auto &i : mp)
    std::cin >> i;
  for (int i = 0; i < n; ++i) {
    for (auto j : mp[i]) {
      contain[i][j - 'a'] = true;
      dp[i] ^= (1 << (j - 'a'));
    }
  }
  i64 ans = 0;
  for (int bit = 0; bit < 26; ++bit) {
    std::map<unsigned int, int> cnt;
    for (int i = 0; i < n; ++i) {
      if (contain[i][bit])
        continue;
      cnt[dp[i]]++;
    }
    for (int i = 0; i < n; ++i) {
      if (contain[i][bit])
        continue;
      int val = MSK ^ dp[i];
      assert((val >> bit) & 1);
      val ^= (1 << bit);
      ans += cnt[val];
    }
  }
  ans /= 2;
  std::cout << ans << "\n";
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  // std::cin >> _;
  while (_--) {
    solve();
  }
}