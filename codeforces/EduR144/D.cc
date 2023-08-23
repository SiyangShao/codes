#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using i64 = long long;
constexpr i64 inf = 1e16;
auto solve() {
  int n, k;
  i64 x;
  std::cin >> n >> k >> x;
  std::vector<i64> a(n);
  for (auto &i : a)
    std::cin >> i, i -= x;
  x *= 2;
  dbg(a, x);
  std::vector<i64> dp(k + 1,
                      -inf); // dp[i]: used i addition, largest presum addition
  dp[0] = 0;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<i64> nxt(k + 1, -inf);
    for (int j = 0; j <= k; ++j) {
      if (dp[j] != -inf) {
        nxt[j] = std::max(nxt[j], 0LL);
        nxt[j] = std::max(nxt[j],
                          std::max(0LL, dp[j]) + a[i]); // add i in the subarray
      }
      if (j && dp[j - 1] != -inf) {
        nxt[j] = std::max(nxt[j], 0LL);
        nxt[j] =
            std::max(nxt[j], std::max(0LL, dp[j - 1]) + a[i] +
                                 x); // add i in the subarray and add x to a[i]
      }
    }
    dbg(nxt);
    dp = std::move(nxt);
    for (int j = 0; j <= k; ++j) {
      if (n - i - 1 >=
          k - j) { // add j elements before a[i] and k - j elements after a[i]
        ans = std::max(ans, dp[j]);
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