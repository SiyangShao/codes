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
unordered_map<ll, vector<ll>> dp;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
ll rev(ll x) { return qpow(x, MOD - 2); }
const ll mul = rev(6);
void init() {
  for (int i = 1; i <= 6; ++i) {
    dp[i].resize(i);
    for (int j = 0; j < i; ++j) {
      dp[i][j] = rev(i);
    }
  }
}
void cal(int n) {
  if (dp.contains(n))
    return;
  dp[n].assign(n, 0);
  dbg(n);
  int x = n * 5 / 6;
  int y = (n * 5 + 5) / 6;
  cal(x), cal(y);
  dbg(dp[x], dp[y]);
  for (int i = 0; i < n; ++i) {
    for (int dice = 0; dice < 6; ++dice) {
      if (i % 6 == dice)
        continue;
      if (n % 6 > dice) {
        // x zhuan
        dbg(i, dice, x);
        if (i % 6 < dice)
          dp[n][i] += mul * dp[x][dbg(i - i / 6)];
        else
          dp[n][i] += mul * dp[x][dbg(i - i / 6 - 1)];
        dp[n][i] %= MOD;
      } else {
        // y zhuan
        dbg(i, dice, y);
        if (i % 6 < dice)
          dp[n][i] += mul * dp[y][dbg(i - i / 6)];
        else
          dp[n][i] += mul * dp[y][dbg(i - i / 6 - 1)];
        dp[n][i] %= MOD;
      }
    }
  }
}
auto solve() {
  int n;
  cin >> n;
  cal(n);
  for (auto i : dp[n]) {
    cout << i << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  // cin >> _;
  while (_--) {
    solve();
  }
}