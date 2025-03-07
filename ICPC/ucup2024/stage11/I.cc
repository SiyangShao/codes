#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> frac(n + 1);
  frac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  int sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  const int SUM = 100 * 100;
  vector<vector<int>> dp(n + 1, vector<int>(SUM + 1, 0));
  // dp[i][j]: use i elements to get sum j
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      for (int k = 0; k + a[i] <= SUM; ++k) {
        dp[j + 1][k + a[i]] += dp[j][k];
        if (dp[j + 1][k + a[i]] >= MOD) {
          dp[j + 1][k + a[i]] -= MOD;
        }
      }
    }
  }
  if (sum % 2 != 0) {
    cout << "0\n";
    return 0;
  }
  sum /= 2;
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ll way = dp[i][sum];
    ans += way * frac[i] % MOD * frac[n - i] % MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
}
