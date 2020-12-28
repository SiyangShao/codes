#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
ll inv(ll x) {
  ll y = MOD - 2, res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
ll frac(ll x, ll y) {
  // return x/y
  return x * inv(y) % MOD;
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll zero = n;
  for (auto &i : a) {
    cin >> i;
    zero -= i;
  }
  ll m = 0;
  for (ll i = 0; i < zero; ++i) {
    m += a[i];
  }
  /**
   * @brief
   * After the array is sorted, all zero should be at first. Thus, if there are
   * m 1s in the first zero's elements, each time we swap 1 in first part and
   * zero in second part, m = m - 1. Otherwise, m doesn't change and the array
   * ramains unsorted. Each time effective swaps is m*m and we have n * (n-1)
   * swaps totally. We need to have m effective swaps. So the answer is  sum of
   * n * (n-1) / 2 / m*2 from 1 to m
   */
  ll ans = 0;
  for (ll i = m; i >= 1; --i) {
    ans = (ans + frac(n * (n - 1) / 2 % MOD, i * i % MOD)) % MOD;
  }
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