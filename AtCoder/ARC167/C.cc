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
constexpr ll N = 5010;
array<ll, N> frac, inv_frac;
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
void init() {
  frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  inv_frac[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (ll i = N - 2; i >= 0; --i) {
    inv_frac[i] = inv_frac[i + 1] * (i + 1) % MOD;
  }
}
ll C(ll x, ll y) {
  if (x < y)
    return 0;
  return frac[x] * inv_frac[y] % MOD * inv_frac[x - y] % MOD;
}
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n);
  for (auto &i : A)
    cin >> i;
  ranges::sort(A);
  ll ans = 0;
  ll preg = 0;
  for (int i = 0; i < n; ++i) {
    ll base = 0;
    for (int j = 1; j <= k; ++j) {
      base = base + C(n - j, i);
      base %= MOD;
    }
    ll g = frac[i + 1] * frac[n - i - 1] % MOD * i % MOD * base % MOD;
    ans = (ans + g * A[i] % MOD) % MOD;
    ans = (ans + MOD - preg * A[i] % MOD) % MOD;
    preg = g;
  }
  cout << ans << "\n";
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