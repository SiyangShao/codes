#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), dp(n, n);
  vector<vector<ll>> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    pos[a[i]].emplace_back(i);
  }
  for (ll i = 0; i < n; ++i) {
    if (pos[i].empty())
      continue;
    ll dif = pos[i][0] - 0 + 1;
    for (int j = 1; j < (int)pos[i].size(); ++j) {
      dif = max(dif, pos[i][j] - pos[i][j - 1]);
    }
    dif = max(dif, n - pos[i].back());
    dp[dif - 1] = min(dp[dif - 1], i);
  }
  ll ans = n;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, dp[i]);
    if (ans == n) {
      cout << "-1 ";
    } else {
      cout << ans + 1 << " ";
    }
  }
  cout << "\n";
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