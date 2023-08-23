#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  string s, t;
  cin >> s >> t;
  int n = (int)s.length(), m = (int)t.length();
  reverse(s.begin(), s.end());
  s = "_" + s, t = "_" + t;
  vector dp(n + 1, vector<ll>(n + 1));
  for (int i = 1; i <= n; ++i) {
    // now the i^th, the previous has covered the first jth and the backward
    // (i-j) th element
    if (n - i + 1 >= m) {
      dp[i - 1][0]++;
      dp[i - 1][0] %= MOD;
    }
    for (int j = 0; j < i; ++j) {
      int new_pos = j + 1;
      if (new_pos > m || s[i] == t[new_pos]) {
        dp[i][j + 1] += dp[i - 1][j];
        dp[i][j + 1] %= MOD;
      }
      new_pos = n - ((i - 1) - j);
      if (new_pos > m || s[i] == t[new_pos]) {
        dp[i][j] += dp[i - 1][j];
        dp[i][j] %= MOD;
      }
    }
  }
  ll ans = 0;
  for (int j = 0; j <= n; ++j) {
    ans += dp[n][j];
    ans %= MOD;
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
