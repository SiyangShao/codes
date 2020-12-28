#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll N = 1e6 + 7;
array<ll, N> frac, inv_frac;
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
void init() {
  frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  inv_frac[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (ll i = N - 1; i > 0; --i) {
    inv_frac[i - 1] = inv_frac[i] * i % MOD;
  }
}
ll A(ll n, ll m) { return frac[n] * inv_frac[n - m] % MOD; }
ll C(ll n, ll m) { return frac[n] * inv_frac[m] % MOD * inv_frac[n - m] % MOD; }
auto solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int dif = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i])
      dif++;
  }
  vector<ll> dp(dif+1, 0);
  for (ll i = dif; i > 0; --i) {
    dp[i] = 
  }
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