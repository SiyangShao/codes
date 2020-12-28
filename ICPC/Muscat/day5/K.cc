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
constexpr int N = 1e6+7;
array<ll, N> frac, inv_frac;
ll qpow(ll x, ll y){
  // if(x==0) return 1;
  ll res = 1;
  while(y){
    if(y&1){
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y>>=1;
  }
  return res;
}
void init(){
  frac[0] = 1;
  for (int i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  inv_frac[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (int i = N - 1; i >= 1; --i) {
    inv_frac[i - 1] = inv_frac[i] * i % MOD;
  }
}
ll A(ll n, ll m) { return frac[n] * inv_frac[n - m] % MOD; }
ll C(ll n, ll m) { return A(n, m) * inv_frac[n] % MOD; }
auto solve(){
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    dbg(k, (k + 1) / 2 - 1, (k - ((k + 1) / 2 - 1)));
    // ll base =

        // C(k - 1, (k + 1) / 2 - 1);
    ll l = qpow(i, (k + 1) / 2 - 1);
    ll r = qpow(n - i + 1, k - ((k + 1) / 2));
    // ll r = A(n - i + 1, (k - ((k + 1) / 2 - 1)));
    // dbg(base, l, r);
    ans += dbg(l % MOD * r % MOD * i % MOD);
    ans %= MOD;
  }
  cout << ans << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  // cin >> _;
  while(_--){
    solve();
  }
}