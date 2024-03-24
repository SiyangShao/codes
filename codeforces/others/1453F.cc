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
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<vector<int>> dp(n, vector<int>(n, n));
  fill(dp[0].begin(), dp[0].end(), 0);
  for (int i = 1; i < n; ++i) {
    int cnt = 0;
    for (int j = i - 1; j >= 0; --j) {
      if (j + a[j] >= i) {
        int nxt = min(j + a[j], n - 1);
        dp[i][nxt] = min(dp[i][nxt], dp[j][i - 1] + cnt);
        cnt++;
      }
    }
    for (int j = 1; j < n; ++j) {
      dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }
  cout << dp.back().back() << "\n";
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