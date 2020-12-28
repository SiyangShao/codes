#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll inv2() {
  ll x = 2, y = MOD - 2, res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  m++;
  vector<int> S(n);
  for (auto &i : S)
    cin >> i;
  S.emplace_back(m);
  vector<vector<ll>> dp(m + 1, vector<ll>(m + 1, 0));
  for (int i = 0; i <= m; ++i) {
    dp[i][m] = m - i;
  }
  for (int i = m - 1; i >= 0; --i) {
    for (int j = m - 1; j > i; --j) {
      dp[i][j] = ((dp[i + 1][j] + 1 + dp[i][j + 1]) % MOD) * inv2() % MOD;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dbg(dp[S[i]][S[i + 1]]);
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