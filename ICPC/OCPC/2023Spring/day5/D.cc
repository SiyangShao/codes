#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e6+1;
constexpr ll MOD = 998'244'353;
array<ll, N> dp;
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
ll rev(ll x) { return qpow(x, MOD - 2); }
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll n, a, b;
  cin >> n >> a >> b;
  ll p = a * rev(b) % MOD;
  dp[0] = 1;
  for (ll i = 0; i + 1 < N; ++i) {
    ll res = 0;
    for (ll j = 0; j <= i; ++j) {
      res = res + qpow(p, j) * qpow((1 - p + MOD) % MOD, i - j) % MOD;
      res %= MOD;
    }
    dp[i + 1] = dp[i] * res % MOD;
  }
  for(ll i = 1; i<N; ++i){
    cout<<dp[i]<<",";
  }
  cout<<endl;
}