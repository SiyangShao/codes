#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n;
  cin >> n;
  ll sum = (1LL << n);
  vector dp(2, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
  dp[0][0][0] = 1;
  vector<ll> fac(sum + 1, 1), res(n + 1);
  for (ll i = 1; i <= sum; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  for (int i = 1; i <= n; ++i) {
    res[i] = (res[i - 1] + (1LL << (n - i)));
  }
  int flg = 1;
  for (int i = 1; i <= sum; ++i) {
    if (i <= n) {
      cout << "0\n";
    } else {
      cout << (dp[flg ^ 1][n][0] + dp[flg ^ 1][n][1]) * sum % MOD *
                  fac[sum - i] % MOD
           << "\n";
    }
    for (int j = 0; j <= n; ++j) {
      dp[flg][j][0] = dp[flg][j][1] = 0;
    }
    for (int j = 0; j <= n; ++j) {
      if (res[j] - (i - 1) >= 1) {
        dp[flg][j][0] =
            (dp[flg ^ 1][j][0] + dp[flg ^ 1][j][1]) * (res[j] - (i - 1)) % MOD;
      }
      if (j >= 1) {
        dp[flg][j][1] = (dp[flg ^ 1][j - 1][1] + dp[flg ^ 1][j - 1][0]) *
                        (1LL << (n - j)) % MOD;
      }
    }
    flg ^= 1;
  }
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