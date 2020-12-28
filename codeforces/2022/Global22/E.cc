#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll N = 1e5 + 7;
array<ll, N> frac, inv_frac;
auto qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
auto init() {
  frac[0] = inv_frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
    inv_frac[i] = inv_frac[i - 1] * qpow(i, MOD - 2) % MOD;
  }
}
auto C(ll n, ll m) {
  if (m > n)
    return 0LL;
  return frac[n] * inv_frac[m] % MOD * inv_frac[n - m] % MOD;
}

auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  function<ll(ll, ll)> dfs = [&](ll i, ll j) {
    ll l = i, r = j;
    while (l <= j && a[l] == 0) {
      l++;
    }
    while (r >= i && a[r] == 0) {
      r--;
    }
    if (l == j + 1) {
      return qpow(2, j - i);
    }
    if (i != l && j != r) {
      ll x = l - i, y = j - r;
      ll c = 0;
      for (ll k = 0; k <= min(x, y); ++k) {
        c = (c + C(x, k) * C(y, k) % MOD) % MOD;
      }
      return dfs(l, r) * c % MOD;
    }
    i = l, j = r;
    ll ls = a[i], rs = a[j];
    while (ls != rs) {
      if (ls < rs) {
        ls += a[++i];
      } else {
        rs += a[--j];
      }
    }
    if (i >= j) {
      return 1LL;
    }
    l = i + 1, r = j - 1;
    while (l <= j && a[l] == 0) {
      l++;
    }
    while (r >= i && a[r] == 0) {
      r--;
    }
    if (l == j) {
      return qpow(2, j - i);
    }
    ll x = l - i - 1, y = j - r - 1;
    ll c = 0;
    for (ll k = 0; k <= min(x, y) + 1; ++k) {
      c = (c + C(x + 1, k) * C(y + 1, k) % MOD) % MOD;
    }
    return dfs(l, r) * c % MOD;
  };
  cout << dfs(1, n) << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}