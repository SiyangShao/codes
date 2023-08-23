#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
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
const ll rev_6 = qpow(6, MOD - 2);
const ll rev_2 = qpow(2, MOD - 2);
auto solve() {
  ll n;
  cin >> n;
  ll bs = n * (n + 1) % MOD * (n * 2 + 1) % MOD * rev_6 % MOD;
  // cout << bs << " ";
  bs = bs * 2 + (1 + n) * n % MOD * rev_2 % MOD;
  bs %= MOD;
  bs = bs - n * n % MOD - n + MOD;
  bs %= MOD;
  bs += MOD;
  bs %= MOD;
  bs *= 2022;
  bs %= MOD;
  cout << bs << "\n";
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
