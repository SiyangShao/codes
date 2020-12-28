#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> ans[i];
  }
  if (n == 1) {
    if (ans[1] == 1)
      cout << "1\n";
    else
      cout << m << "\n";
    return;
  } else if (m >= n - 1) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (ans[i] == 0)
        cnt++;
    }
    cout << qpow(m, cnt) << "\n";
    return;
  }
  vector dp(n + 1, vector<ll>(m + 2, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == 1) {
      for (int j = 0; j <= m; ++j) {
        dp[i][j + 1] += dp[i - 1][j];
        if (dp[i][j + 1] >= MOD)
          dp[i][j + 1] -= MOD;
      }
    } else {
      for (int j = 0; j <= m - 1; ++j) {
        dp[i][j + 1] += dp[i - 1][j] * (m - j) % MOD;
        if (dp[i][j + 1] >= MOD)
          dp[i][j + 1] -= MOD;
      }
      for (int j = 1; j <= m + 1; ++j) {
        dp[i][j] += dp[i - 1][j] * j % MOD;
        if (dp[i][j] >= MOD)
          dp[i][j] -= MOD;
      }
    }
  }
  ll res = 0;
  for (int i = 0; i <= m + 1; ++i) {
    res += dp[n][i];
    if (res >= MOD)
      res -= MOD;
  }
  cout << res << "\n";
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