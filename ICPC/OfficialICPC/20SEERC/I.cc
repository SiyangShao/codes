/**
 * Dp[i]: number of selections *end with i*
 * Remember: next array's new begin is i-1
 * So we can use dp[(i-1) * k + 0 / 1 / 2] and add it to the end of next
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll n;
  cin >> n;
  if (n <= 2) {
    cout << n << "\n";
    return 0;
  }
  vector<ll> dp(n + 1, 0);
  dp[n] = 1;
  for (ll i = n - 1; i >= 4; --i) {
    dp[i] = 1;
    for (ll k = 1; k * (i - 1) <= n; ++k) {
      for (ll x = k * (i - 1); x <= k * (i - 1) + 2; ++x) {
        if (x > n || x <= i) {
          continue;
        }
        dp[i] += dp[x];
        dp[i] %= MOD;
      }
    }
  }
  // 2 * k will inteact, so special check 3
  dp[3] = 1;
  for (ll i = 4; i <= n; ++i) {
    dp[3] += dp[i];
    dp[3] %= MOD;
  }
  ll ans = 1;
  for (ll i = 3; i <= n; ++i) {
    ans += dp[i];
    ans %= MOD;
  }
  cout << (ans * n) % MOD << "\n";
}