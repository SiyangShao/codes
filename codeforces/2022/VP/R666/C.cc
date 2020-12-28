#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  assert(r1 <= r2 && r2 <= r3);
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector dp(2, vector<ll>(n, inf));
  dp[0][0] = r1 * a[0] + r3;
  dp[1][0] = min(r2, r1 * a[0] + r1);
  for (ll i = 1; i < n; ++i) {
    dp[0][i] = min(dp[0][i], dp[0][i - 1] + d + r1 * a[i] + r3);
    dp[1][i] = min(dp[1][i], dp[0][i - 1] + d + min(r2, r1 * a[i] + r1));
    dp[0][i] = min(dp[0][i], dp[1][i - 1] + d + r1 * a[i] + r3 + 2 * d + r1);
    dp[0][i] =
        min(dp[0][i], dp[1][i - 1] + d + r1 * a[i] + r1 + d + r1 + d + r1);
    dp[0][i] = min(dp[0][i], dp[1][i - 1] + d + r2 + d + r1 + d + r1);
    dp[1][i] = min(dp[1][i], dp[1][i - 1] + d + r2 + d + r1 + d);
    dp[1][i] = min(dp[1][i], dp[1][i - 1] + d + r1 * a[i] + r1 + d + r1 + d);
    if (i == n - 1) {
      dp[0][i] = min(dp[0][i], dp[1][i - 1] + d + r1 * a[i] + r3 + d + r1);
    }
  }
  cout << dp[0][n - 1] << "\n";
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