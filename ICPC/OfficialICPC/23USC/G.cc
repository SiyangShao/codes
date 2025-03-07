#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  ll r, c, p;
  cin >> r >> c >> p;
  vector<vector<ld>> dp(r, vector<ld>(c));
  dp[0][0] = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == 0 && j == 0)
        continue;
      if (i == 0) {
        // only can from i, j-1
        dp[i][j] = dp[i][j - 1] + ((ld)p / 4.0);
      } else if (j == 0) {
        // only can from i-1, j
        dp[i][j] = dp[i - 1][j] + ((ld)p / 4.0);
      } else {
        auto a = dp[i - 1][j], b = dp[i][j - 1];
        if (a > b)
          swap(a, b);
        // a < b
        if (b > a + p) {
          // will go a in any case
          dp[i][j] = a + (ld)p / 4.0;
        } else {
          // case 1: now point is a
          dp[i][j] = a / 2.0;
          // case 2: now point is b, and res time > b - a
          ld res_is = 1 - (b - a) / p;
          dp[i][j] += (b)*res_is / 2.0;
          // case 3: now point is b, and res time < b - a
          dp[i][j] += (a + (b - a) / 2) * (1 - res_is) / 2.0;
        }
      }
    }
  }
  cout << fixed << setprecision(10) << dp[r - 1][c - 1] << '\n';
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}