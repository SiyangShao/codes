#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  n *= 2;
  vector<pair<ll, int>> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i].first;
    c[i].second = i;
  }
  auto check = [&](auto u, auto v) {
    if (abs(u.second - v.second) == 1 && min(u.second, v.second) % 2 == 0)
      return false;
    return true;
  };
  sort(c.begin(), c.end());
  constexpr ll inf = 1e16;
  vector<array<ll, 2>> dp(n / 2, {inf, inf});
  // 0: with after
  // 1: no with after
  if (check(c[0], c[1])) {
    dp[0][1] = dp[0][0] = c[1].first - c[0].first;
  } else {
    dp[0][0] = c[1].first - c[0].first;
  }
  for (int i = 3; i < n; i += 2) {
    auto u = c[i - 1], v = c[i];
    auto prev = c[i - 2];
    auto x = i / 2;
    if (check(u, v)) {
      dp[x][0] = dp[x][1] = v.first - u.first + dp[x - 1][1];
      dp[x][1] = min(dp[x][1], dp[x - 1][0] + v.first - u.first +
                                   (u.first - prev.first) * 2);
      dp[x][0] = min(dp[x][0], dp[x][1]);
    } else {
      dp[x][0] = v.first - u.first + dp[x - 1][1];
      dp[x][1] = v.first - u.first + min(dp[x - 1][0], dp[x - 1][1]) +
                 2 * (u.first - prev.first);
      dp[x][0] = min(dp[x][0], dp[x][1]);
    }
  }
  cout << dp[n / 2 - 1][1] << "\n";
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