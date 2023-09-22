#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
map<ll, ll> f, g;
void dfs(ll x) {
  if (f.contains(x))
    return;
  if (x & 1) {
    dfs(x / 2);
    g[x] = g[x / 2];
    f[x] = f[x / 2] * 2 + g[x];
    f[x] %= MOD;
  } else {
    dfs(x / 2);
    dfs(x / 2 - 1);
    g[x] = g[x / 2] + g[x / 2 - 1];
    f[x] = (f[x / 2] + f[x / 2 - 1]) * 2;
    f[x] %= MOD;
  }
}
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
auto solve() {
  ll n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << n % MOD << "\n";
    return;
  }
  if (m >= 3) {
    ll num = (n + 2) / 2;
    num %= MOD;
    ll ans;
    if ((n % 2) == 0) {
      ans = (n / 2) % MOD * num % MOD;
    } else {
      ans = ((1 + n) / 2) % MOD * num % MOD;
    }
    cout << ans << "\n";
    return;
  }
  dfs(n);
  cout << f[n] << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  f[0] = 0, g[0] = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}