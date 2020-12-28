#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 200010;
array<ll, N> frac, invFrac;
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
void init() {
  frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  invFrac[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (ll i = N - 2; i >= 0; --i) {
    invFrac[i] = invFrac[i + 1] * (i + 1) % MOD;
  }
}
ll C(ll n, ll m) {
  if (n < m)
    return 0;
  return frac[n] * invFrac[m] % MOD * invFrac[n - m] % MOD;
}
auto solve() {
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp;
  for (ll i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;
    mp[l]++;
    mp[r + 1]--;
  }
  ll sum = 0;
  ll ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    auto nxt = next(it);
    sum += it->second;
    assert(sum >= 0);
    if (nxt != mp.end() && sum >= k) {
      ll len = (nxt->first) - (it->first);
      ans += C(sum, k) * len % MOD;
      ans = ans % MOD;
    }
  }
  cout << ans << "\n";
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