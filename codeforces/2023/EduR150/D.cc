#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  // read input
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (auto &[l, r] : vec) {
    cin >> l >> r;
  }
  // sort by left endpoint
  ranges::sort(vec);
  // dp[i][0] - max number of intervals that can be chosen from the first i intervals
  // dp[i][1] - max number of intervals that can be chosen from the first i intervals and i-th interval is chosen
  vector dp(n, vector<ll>(2, 0));
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    // base case: i-th interval is chosen
    dp[i][0] = max(dp[i][0], 1LL);
    auto [l1, r1] = vec[i];
    for (int j = 0; j < i; ++j) {
      auto [l2, r2] = vec[j];
      // case 1: j-th interval is chosen
      if (l1 <= r2) {
        // case 1.1: i-th interval is chosen
        if (r1 >= r2) {
          dp[i][1] = max(dp[i][1], dp[j][0] + 1);
          ans = max(ans, dp[i][1]);
        }
        // case 1.2: i-th interval is not chosen
        else {
          dp[j][1] = max(dp[j][1], dp[j][0] + 1);
          ans = max(ans, dp[j][1]);
        }
      }
      // case 2: j-th interval is not chosen
      else {
        dp[i][0] = max(dp[i][0], dp[j][1] + 1);
      }
    }
  }
  cout << n - ans << "\n";
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