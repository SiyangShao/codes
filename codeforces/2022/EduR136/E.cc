#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<string> mp(2);
  cin >> mp[0] >> mp[1];
  vector dp(2, vector<ll>(n + 2, 0));
  for (ll i = n - 2; i >= 0; --i) {
    for (ll p = 0; p <= 1; ++p) {
      if (mp[p ^ 1][i] == '1' && mp[p][i + 1] == '1') {
        dp[p][i] = min(dp[p ^ 1][i + 2] + 1, dp[p][i + 1] + 1);
      } else if (mp[p ^ 1][i] == '1') {
        dp[p][i] = min(dp[p ^ 1][i + 1], dp[p][i + 1] + 1);
      } else if (mp[p][i + 1] == '1') {
        dp[p][i] = dp[p][i + 1];
      } else {
        dp[p][i] = dp[p][i + 1];
      }
    }
  }
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ans += mp[0][i] - '0';
    ans += mp[1][i] - '0';
  }
  cout << ans - dp[0][0] << "\n";
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