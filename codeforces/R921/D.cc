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
constexpr int N = 4e3 + 7;
array<ll, N> frac, invFrac;
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
ll inv(ll x) { return qpow(x, MOD - 2); }
void init() {
  frac[0] = 1;
  for (int i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  invFrac[N - 1] = inv(frac[N - 1]);
  for (int i = N - 2; i >= 0; --i) {
    invFrac[i] = invFrac[i + 1] * (i + 1) % MOD;
  }
}
ll C(ll x, ll y) { return frac[x] * invFrac[y] % MOD * invFrac[x - y] % MOD; }
map<tuple<ll, ll, ll>, ll> mp;
ll f(ll n, ll m, ll k) {
  if (k >= min(n, m))
    return C(n + m, m);
  else
    return C(n + m, k);
}
auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  cout << (f(n, m, k) - f(n, m, k - 1) + MOD) % MOD << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}