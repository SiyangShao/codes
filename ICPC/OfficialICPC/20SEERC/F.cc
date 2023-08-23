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
  /**
   * @brief
   * All h[i] are distinct!!! Suppose dp[i][j]: use first i elements get length
   * of j's cases. Then, dp[i+1][j] = sum (dp[i][k]), in which k from l[i]
   * to j.
   */
  vector<ll> dp(n), pre(n);
  for (ll i = 0; i < n; ++i) {
    if (l[i] <= 0) {
      dp[i] = 1;
    }
    pre[i] = ((i == 0 ? 0 : pre[i - 1]) + dp[i]) % MOD;
  }
  for (ll i = 1; i < n; ++i) {
    vector<ll> nxt(n);
    for (ll j = 0; j < n; ++j) {
      if (l[j] <= i && r[j] >= i) {
        nxt[j] = (nxt[j] + pre[j]) % MOD;
      }
      pre[j] = ((j == 0 ? 0 : pre[j - 1]) + nxt[j]) % MOD;
    }
    dp = move(nxt);
  }
  ll ans = 0;
  for (auto &i : dp) {
    ans = (ans + i) % MOD;
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