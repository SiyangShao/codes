#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> h(n), l(n), r(n);
  for (auto &i : h) {
    cin >> i;
  }
  for (ll i = 0; i < n; ++i) {
    l[i] = r[i] = i;
    for (ll j = i - 1; j >= 0; --j) {
      if (h[j] > h[i]) {
        l[i] = j;
      } else {
        break;
      }
    }
    for (ll j = i + 1; j < n; ++j) {
      if (h[j] > h[i]) {
        r[i] = j;
      } else {
        break;
      }
    }
  }
  vector<ll> dp(n);
  for (ll i = 0; i < n; ++i) {
    for (ll j = l[i]; j <= r[i]; ++j) {
      dp[j] = (dp[j] + (j == 0 ? 1 : dp[j - 1])) % MOD;
      // For ith: Left most is L[i], Right most is R[i]
    }
  }
  cout << dp[n - 1] << "\n";
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