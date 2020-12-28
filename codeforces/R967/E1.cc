#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll K = 512;
array<ll, K> modInv;
ll qpow(ll x, ll y, const ll p) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % p;
    }
    x = x * x % p;
    y >>= 1;
  }
  return res;
}
void init(int k, const ll p) {
  for (int t = 0; t <= k; ++t) {
    modInv[t] = qpow(t, p - 2, p);
  }
}
auto solve() {
  int n, k;
  ll p;
  cin >> n >> k >> p;
  vector dp(n, vector<ll>(k + 1));
  vector dp_sum(n, vector<ll>(k + 1));
  init(k, p);
  dp[0][k] = 1;
  for (int i = 0; i <= k; ++i) {
    dp_sum[0][i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    ll tmp = (qpow(2, n - i, p) - 1 + p) % p;
    for (int j = 1; j <= k; ++j) {
      ll c = 1;
      for (int t = 0; t < j && t + j <= k; ++t) {
        if (t >= 1) {
          c = c * (t + tmp - 1 + p) % p * modInv[t] % p;
        }
        dp[i][j] += dp_sum[i - 1][j + t] * c % p * 2 % p;
        dp[i][j] %= p;
      }
    }
    for (int j = k; j >= 1; --j) {
      dp_sum[i][j] = ((j == k ? 0 : dp_sum[i][j + 1]) + dp[i][j]) % p;
    }
  }
  ll res = 0;
  for (int j = 1; j <= k; ++j) {
    res = (res + dp[n - 1][j]) % p;
  }
  cout << res << "\n";
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
