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
constexpr ll N = 2e5 + 7;

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
ll divv(ll x, ll y) {
  x %= MOD, y %= MOD;
  return x * rev(y) % MOD;
}
array<ll, N> frac, invFrac;
void init() {
  frac[0] = 1;
  for (int i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  invFrac[N - 1] = rev(frac[N - 1]);
  for (int i = N - 1; i > 0; --i) {
    invFrac[i - 1] = invFrac[i] * i % MOD;
  }
}
ll C(ll n, ll m) {
  if (n < m)
    return 0LL;
  return frac[n] * invFrac[m] % MOD * invFrac[n - m] % MOD;
}
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  if (k % 2 == 1) {
    // when k is odd, there should always be only one good island
    cout << "1\n";
    return;
  } else {
    vector<int> size(n);
    ll ans = 1;
    function<void(int, int)> dfs = [&](int u, int fa) {
      size[u] = 1;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        ans = (ans + divv(C(size[v], k / 2) * C(n - size[v], k / 2), C(n, k))) %
              MOD;
        // contribution of edge u-v
        size[u] += size[v];
      }
    };
    dfs(0, 0);
    cout << ans << "\n";
  }
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