#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 MOD = 998'244'353;
array<array<i64, 128>, 128> dp, g;
array<i64, 128> dp2, g2;
void init() {
  for (int i = 1; i <= 60; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j < i; ++j) {
      dp[i][j] = dp[i - 1][j - 1] * 2 % MOD;
    }
    for (int j = 0; j <= i * 2 - 2; ++j) {
      g[i][j] = (g[i][j] + g[i - 1][j] * 2 + dp[i][j]) % MOD;
      for (int k = 0; k <= j; ++k) {
        g[i][j + 2] =
            (g[i][j + 2] + dp[i - 1][k] * dp[i - 1][j - k] % MOD) % MOD;
      }
    }
  }
}
i64 lef_dep(i64 n, i64 val, i64 res = 0) {
  if (val > n)
    return res;
  return lef_dep(n, val * 2, res + 1);
}
i64 rig_dep(i64 n, i64 val, i64 res = 0) {
  if (val > n)
    return res;
  return rig_dep(n, val * 2 + 1, res + 1);
}
bool full_binary(i64 n, i64 val) { return lef_dep(n, val) == rig_dep(n, val); }
void dfs(i64 n, i64 root) {
  if (root * 2 > n) {
    g2[0] = dp2[0] = 1;
    return;
  }
  if (root * 2 == n) {
    g2[0] = 2, g2[1] = 1;
    dp2[0] = 1, dp2[1] = 1;
    return;
  }
  i64 d = 0;
  if (full_binary(n, root * 2)) {
    d = lef_dep(n, root * 2);
    dfs(n, root * 2 + 1);
  } else {
    d = lef_dep(n, root * 2 + 1);
    dfs(n, root * 2);
  }
  i64 mx = 2 * d + 4;
  for (i64 i = 0; i <= mx; i++) {
    g2[i] += g[d][i];
    for (i64 j = 0; j <= min(d + 2, i); j++) {
      g2[i + 2] += dp2[j] * dp[d][i - j] % MOD;
    }
  }
  for (i64 i = mx; i > 0; i--)
    dp2[i] = (dp2[i - 1] + dp[d][i - 1]) % MOD;
  dp2[0] = 1;
  for (i64 i = 0; i <= mx; i++) {
    g2[i] += dp2[i];
    g2[i] %= MOD;
  }
}
i64 qpow(i64 x, i64 y) {
  i64 res = 1;
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
  i64 n, m;
  cin >> n >> m;
  dfs(n, 1);
  i64 d = lef_dep(n, 1), ans = 0;
  // cout << d << " ";
  vector<i64> f(d * 2);
  for (i64 i = 0; i <= 2 * d - 2; ++i) {
    for (i64 j = 1; j <= m; ++j) {
      f[i] += (qpow(j, i + 2) + MOD - qpow(j - 1, i + 1) * j % MOD) % MOD;
      f[i] %= MOD;
    }
    if (n >= i + 1) {
      ans += f[i] * g2[i] % MOD * qpow(m, n - i - 1) % MOD;
      ans %= MOD;
    }
  }
  fill(g2.begin(), g2.end(), 0);
  fill(dp2.begin(), dp2.end(), 0);
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  init();
  while (_--) {
    solve();
  }
}