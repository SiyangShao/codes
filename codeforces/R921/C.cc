#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 999'999'893;
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
  int n;
  cin >> n;
  ll a = qpow(2, (n + 1) / 2), b = (qpow(2, n / 2) + MOD - 1) % MOD;
  ll c = a * a % MOD - b * b * 2 % MOD;
  c = (c % MOD + MOD) % MOD;
  ll ans = 2 * b * qpow(c, MOD - 2);
  ans = (ans % MOD + MOD) % MOD;
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