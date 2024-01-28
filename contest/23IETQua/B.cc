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
  x %= MOD;
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
auto solve() {
  ll n;
  cin >> n;
  if (n <= 3) {
    cout << n << "\n";
  } else {
    ll base = n % 3;
    if (base == 0)
      base = 1;
    if (n % 3 == 1) {
      n -= 4;
      base = 4;
    }
    ll num = n / 3;
    base = base * qpow(3, num) % MOD;
    cout << base << "\n";
  }
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