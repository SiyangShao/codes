#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  ll N, A, B;
  cin >> N >> A >> B;
  ld k = 1, L = B - A + 1;
  vector<ld> dp(N + 1);
  if (A == 0) {
    k = L / (L - 1);
  }
  dp[0] = 0;
  for (ll i = 1; i <= min(A, N); ++i) {
    dp[i] = 1;
  }
  ld prefixsum = 0;
  for (ll i = A + 1; i <= N; ++i) {
    dp[i] = k;
    if (i - A >= 0) {
      if (A == 0) {
        if (i - A - 1 >= 0) {
          prefixsum += dp[i - A - 1];
        }
      } else {
        prefixsum += dp[i - A];
      }
    }
    if (i - B - 1 >= 0) {
      prefixsum -= dp[i - B - 1];
    }
    dp[i] += k * prefixsum / L;
  }
  cout << std::fixed << setprecision(10) << dp[N] << "\n";
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