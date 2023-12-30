#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll N = 1e7 + 7;
array<ll, N> frac, inv;
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
auto init() {
  frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  inv[N - 1] = qpow(N - 1, MOD - 2);
  for (ll i = N - 2; i >= 0; --i) {
    inv[i] = inv[i + 1] * (i + 1) % MOD;
  }
}
ll C(ll x, ll y) {
  if (x < y)
    return 0;
  return (frac[x] * inv[y]) % MOD * inv[x - y] % MOD;
}
auto solve() {
  ll n, a, x, y, m, k;
  cin >> n >> a >> x >> y >> m >> k;
  vector<ll> A(n);
  A[0] = a;
  for (ll i = 1; i < n; ++i) {
    A[i] = (A[i - 1] * x + y) % m;
  }
  for (ll i = 0; i <= k; ++i) {
    for (ll j = 1; j < n; ++j) {
      A[j] = (A[j] + A[j - 1]) % MOD;
    }
  }
  ll ans = 0;
  for (ll i = k - 1; i < n; ++i) {
    ans ^= (i + 1) * A[i - k + 1];
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