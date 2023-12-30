#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
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
ll frac(ll x, ll y) { return x * rev(y) % MOD; }
constexpr ll N = 510;
array<array<ll,N>, N> C;
auto init(){
  for(int i = 0 ; i < N; ++i){
    C[i][0] = 1;
    for(int j = 1; j<=i; ++j){
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
}
auto solve() {
  ll n, p;
  cin >> n >> p;
  p = frac(p, 10000);
  ll q = (1 + MOD - p) % MOD;
  vector g(n + 1, vector<ll>(n + 1, 0));
  g[1][0] = 1;
  for(ll i = 2; i <= n; ++i){
    for(ll k = 1; k<= i; ++k){
      
    }
  }
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