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
// ll C(ll x, ll y){
//   return 0LL;
// }
auto solve() {
  ll n, k;
  cin >> n >> k;
  k = gcd(n, k);
  ll x = (qpow(2, n / k) + MOD - 1) % MOD;

  ll ans = qpow(x, k) * (k + 1) % MOD;
  // cout << ans << " ";
  ans = ans - (x - 1) * k % MOD * qpow(x, k - 1) % MOD;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  cout << ans << "\n";
  // for(int i = 0; i <= k; ++i){
  //   ans += qpow(x - 1, i) * C(k, i) * (k - i + 1);
  //   ans %= MOD;
  // }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}