#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  vector<vector<int>> g(n + 1);
  for (auto &[l, r] : p) {
    cin >> l >> r;
    g[l].emplace_back(r);
  }
  vector dp(n + 1, vector<ll>(n + 1, -inf));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    // consider all number from 1 to i, has j 1, number of 1-0
    if (g[i].empty()) {
      // a[i] could be 0 or 1. doesn't matter
      for (int j = 0; j < i; ++j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + j);
      }
      // a[i] be 1:
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    } else {
      assert(g[i].size() == 1);
      int l = i, r = g[i][0];
      for (int num_zero = 1; num_zero <= r - l; ++num_zero) {
        int num_one = r - l + 1 - num_zero;
        dbg(num_zero, num_one);
        for (int j = 0; j <= l - 1; ++j) {
          dp[r][j + num_one] =
              max(dp[r][j + num_one], dbg(dp[l - 1][j] + (ll)j * num_zero));
        }
      }
      i = g[i][0];
    }
    dbg(i, dp[i]);
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ll res = dp[n][i] + (ll)i * (i - 1) / 2 + (ll)(n - i) * (n - i - 1) / 2;
    ans = max(ans, res);
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