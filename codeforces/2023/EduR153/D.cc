#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  int one = 0;
  for (auto i : s) {
    if (i == '1')
      one++;
  }
  int zero = n - one;
  int need =
      (n * (n - 1) / 2 - zero * (zero - 1) / 2 + one * (one - 1) / 2) / 2;
  constexpr int inf = 1e9;
  vector dp(n + 1, vector<int>(need + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = one; j >= 1; --j) {
      for (int k = i; k <= need; ++k) {
        dp[j][k] = min(dp[j][k], dp[j - 1][k - i] + (s[i] == '0' ? 1 : 0));
      }
    }
  }
  cout << dp[one][need] << "\n";
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