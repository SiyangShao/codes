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
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ranges::sort(a, greater<>());
  vector<int> dp(n + 1);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = a[i - 1];
    dp[i] += dp[i - 1];
  }
  int ans = -1e9;
  for (int i = 0; i <= k; ++i) {
    ans = max(ans, dp[n] - 2 * dp[min(i + x, n)] + dp[i]);
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