#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
ll qpow(ll x, ll y) {
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
  int n;
  cin >> n;
  vector<ll> w(n);
  for (auto &i : w)
    cin >> i;
  ll ans = 1;
  ll tri = n / 3;
  for (ll i = 1; i <= tri; ++i) {
    ans *= i;
    ans %= MOD;
  }
  for (ll i = 1; i <= tri / 2; ++i) {
    ll x = qpow(i, MOD - 2);
    x = x * x % MOD;
    ans *= x;
    ans %= MOD;
  }
  for (int i = 0; i < n; i += 3) {
    if (w[i] == w[i + 1] && w[i + 1] == w[i + 2]) {
      ans *= 3;
      ans %= MOD;
    } else {
      sort(w.begin() + i, w.begin() + i + 3);
      if (w[i] == w[i + 1]) {
        ans *= 2;
        ans %= MOD;
      }
    }
  }
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