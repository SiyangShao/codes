#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qpow(ll x, ll y, ll MOD) {
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
auto solve() {
  ll n, MOD;
  cin >> n >> MOD;
  vector<ll> frac(n + 1), invfrac(n + 1);
  frac[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  invfrac[n] = qpow(frac[n], MOD - 2, MOD);
  for (ll i = n - 1; i >= 0; --i) {
    invfrac[i] = invfrac[i + 1] * (i + 1) % MOD;
  }
  function<ll(ll, ll)> C = [&](ll x, ll y) {
    return frac[x] * invfrac[y] % MOD * invfrac[x - y] % MOD;
  };
  ll ans = (n & 1) ? 0 : frac[n - 2];
  for (ll i = 1; i * 2 < n; ++i) {
    for (int j = 0; j < i; ++j) {
      ans += (i + !(n & 1)) * frac[n - 3 - j] % MOD * C(i - 1, j) % MOD;
      ans %= MOD;
    }
  }
  ans = ans * n % MOD;
  cout << ans << "\n";
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