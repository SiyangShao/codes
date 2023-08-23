#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
using i128 = __int128;
long long qpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

bool is_prime(ll x) {
  if(x < 2){
    return false;
  } 
  for(ll i =2; i*i<=x; ++i){
    if (x % i == 0)
      return false;
  }
  return true;
}
// Can't situation
// 1. can't have more than 1 1
// 2. 1 must be at first
// 3. for i = 2 to n, a[i] %i == 0
// 4. a[i] % (i-1) == 0
auto solve() {
  ll n, m;
  cin >> n >> m;
  ll bs = 0;
  ll mul = 1, ans = m % MOD;
  bool flag = false;
  for (ll i = 2; i <= n; ++i) {
    bs = bs + qpow(m, i);
    bs %= MOD;
    if (flag)
      continue;
    if (is_prime(i)) {
      if (i128(mul) * i128(i) > i128(m)) {
        flag = true;
        continue;
      } else {
        mul *= i;
      }
    }
    ll num = m / mul;
    num %= MOD;
    ans %= MOD;
    ans = ans * num % MOD;
    bs = bs + MOD - ans;
    bs %= MOD;
  }
  cout << bs << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}