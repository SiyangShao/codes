#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector dp(n + 1, vector<ll>(k + 1, 0));
  ll ans = 0;
  fill(dp[0].begin() + 1, dp[0].end(), 1);
  for (int sum = 1; sum <= n; ++sum) {
    for (int cur = 1; cur <= k; ++cur) {
      for (int prev = 1; cur * prev <= sum && cur + prev - 1 <= k; prev++) {
        dp[sum][cur] = (dp[sum][cur] + dp[sum - cur * prev][prev]) % MOD;
      }
      if (sum == n) {
        ans = (ans + dp[sum][cur]) % MOD;
      }
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