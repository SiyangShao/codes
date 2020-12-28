#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e18;
auto solve() {
  ll p1, t1, p2, t2;
  cin >> p1 >> t1 >> p2 >> t2;
  ll h, s;
  cin >> h >> s;
  vector<ll> dp(h, inf);
  ll ans = inf;
  dp[0] = 0;
  for (ll i = 0; i < h; ++i) {
    for (ll j = 1; j <= 5000; ++j) {
      ll k = j * t1 / t2;
      if (k == 0) {
        if (i + j * (p1 - s) >= h) {
          ans = min(ans, dp[i] + j * t1);
        }
        continue;
      }
      ll d = p1 * j + p2 * k - (j + k - 1) * s;
      if (d + i < h) {
        dp[d + i] = min(dp[d + i], dp[i] + j * t1);
      } else {
        ans = min(ans, dp[i] + j * t1);
        break;
      }
    }
    for (ll j = 1; j <= 5000; ++j) {
      ll k = j * t2 / t1;
      if (k == 0) {
        if (i + j * (p2 - s) >= h) {
          ans = min(ans, dp[i] + j * t2);
        }
        continue;
      }
      ll d = p2 * j + p1 * k - (j + k - 1) * s;
      if (d + i < h) {
        dp[d + i] = min(dp[d + i], dp[i] + j * t2);
      } else {
        ans = min(ans, dp[i] + j * t2);
        break;
      }
    }
  }
  cout << ans << "\n";
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