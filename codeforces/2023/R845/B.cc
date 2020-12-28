#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll qpow(ll x, ll y) {
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
constexpr ll rev2 = qpow(2, MOD - 2);
auto solve() {
  ll n;
  cin >> n;
  ll bs = 1, cnt = 0;
  for (ll i = 1; i <= n; ++i) {
    bs *= i;
    bs %= MOD;
    cnt += i - 1;
    cnt %= MOD;
  }
  ll ans = bs * n % MOD * (n - 1) % MOD * rev2 % MOD + cnt * bs % MOD;
  ans %= MOD;
  cout << ans << "\n";
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