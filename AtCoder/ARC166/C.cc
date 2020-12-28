#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int N = 2e6 + 7;
array<ll, N> feb, febaccumulate;
void init() {
  feb[0] = 1;
  feb[1] = 1;
  for (int i = 2; i < N; ++i) {
    feb[i] = (feb[i - 1] + feb[i - 2]) % MOD;
  }
  febaccumulate[0] = 1;
  for (int i = 2; i < N; i += 2) {
    febaccumulate[i] = feb[i] * febaccumulate[i - 2] % MOD;
  }
}
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
  int n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  m = m - n;
  ll ans = dbg(febaccumulate[n * 2]) * febaccumulate[n * 2] % MOD *
           dbg(qpow(feb[n * 2 + 1], m)) % MOD;
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}