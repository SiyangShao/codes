#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &i : a)
    cin >> i;

  ll lim = (ll)sqrtl(n * 2);
  vector dp(lim + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (a[i] <= lim) {
      dp[a[i]][b[i]]++;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= lim) {
      if (a[i] * a[i] - b[i] > 0 && a[i] * a[i] - b[i] <= n) {
        ans += dp[a[i]][a[i] * a[i] - b[i]];
      }
    }
  }
  for (int i = 2; i <= lim; i += 2) {
    ans -= dp[i][i * i / 2];
  }
  ans /= 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= lim && j < a[i] && j * a[i] <= 2LL * n; ++j) {
      if (j * a[i] - b[i] > 0 && j * a[i] - b[i] <= n) {
        ans += dp[j][j * a[i] - b[i]];
      }
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}