#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto qpow(ll x, ll y) {
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
constexpr ll N = 3e5 + 7;
array<ll, N> fac, inv_fac, inv, I;
auto init() {
  fac[0] = inv_fac[0] = 1;
  inv[1] = 1;
  for (ll i = 2; i < N; ++i) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  }
  for (ll i = 1; i < N; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv_fac[i] = inv_fac[i - 1] * inv[i] % MOD;
  }
  I[1] = I[0] = 1, I[2] = 2;
  // I[x]: number of permutations with cycles only of length 2 and 1
  // 1: the xth appear in sigle, I[x-1]
  // 2: the xth appear in cycle, (x-1) * I[x-2]
  for (ll i = 3; i < N; ++i) {
    I[i] = I[i - 1] + (i - 1) * I[i - 2] % MOD;
    I[i] %= MOD;
  }
}
auto C(ll n, ll k) {
  if (k > n)
    return 0LL;
  return (fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD);
}
auto A(ll n, ll k) {
  if (k > n)
    return 0LL;
  return (fac[n] * inv_fac[n - k] % MOD);
}
auto solve() {
  ll n;
  cin >> n;
  // 3 types:
  // i
  // i, j
  // i, j, i+1, j+1
  // enume number of loop 3
  ll ans = 0;
  for (ll s = 0; s <= n / 4; ++s) {
    // i, j, i+1, j+1. Firstly, pick 2s non-neighbour elements from [1, n-1]
    // which is C(n-s*2, s*2)
    // permulate each and group in members of 2.
    // (2s)! / s!
    ll tmp = C(n - s * 2, s * 2) * fac[s * 2] % MOD * inv_fac[s] % MOD;
    tmp = tmp * I[n - s * 4] % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << "\n";
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