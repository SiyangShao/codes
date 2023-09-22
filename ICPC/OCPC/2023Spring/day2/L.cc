#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 9;
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
  ll n, m;
  cin >> n >> m;
  ll x = n * (n - 1) % MOD;
  x *= rev(2);
  x %= MOD;
  ll up = x;
  for (ll i = m + 1; i <= n; ++i) {
    x = x * i % MOD;
  }
  ll y = 1;
  for (ll i = 1; i < m; ++i) {
    x = x * ((up - i + MOD) % MOD) % MOD;
    x %= MOD;
  }
  for (ll i = n + 1; i <= m; ++i) {
    y = y * i % MOD;
    y %= MOD;
  }
  y = rev(y);
  x = x * y % MOD;
  cout << x << "\n";
}