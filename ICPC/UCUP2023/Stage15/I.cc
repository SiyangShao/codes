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
  int a, b, m;
  cin >> a >> b >> m;
  vector<ll> dp(m + 1, 0);
  ll base = 0;
  for (int i = 0; i <= m; ++i) {
    if (i + b <= m) {
      dp[i + b] = max(dp[i + b], dp[i] + b / a + 1);
    }
    int cnt = (b + a - 1) / a;
    if (i + a * cnt <= m) {
      dp[i + a * cnt] = max(dp[i + a * cnt], dp[i] + cnt + 1);
    }
    base = max(base, dp[i] + (m - i) / a);
  }
  cout << base * 160 + 320 << "\n";
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