#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 2e5 + 7;
array<ll, N> p, inv;
auto init() {
  p[0] = 1;
  for (ll i = 1; i < N; ++i) {
    p[i] = p[i - 1] * 2 % MOD;
  }
  inv[1] = 1;
  for (ll i = 2; i < N; ++i) {
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
  }
}
auto solve() {
  ll n, k;
  cin >> n >> k;
  if (k >= n) {
    cout << p[n] << "\n";
    return;
  }
  ll ans = 0, bs = 1;
  for (ll i = 0; i <= k; ++i) {
    ans += bs;
    ans %= MOD;
    bs = bs * (n - i) % MOD * inv[i + 1] % MOD;
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