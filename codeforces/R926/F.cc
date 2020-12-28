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
constexpr int N = 5e5 + 7;
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

ll C(ll x, ll y) {
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  return C(x, y - 1) * (x - y + 1) % MOD * qpow(y, MOD - 2) % MOD;
}
auto solve() {
  int n;
  cin >> n;
  ll c;
  cin >> c;
  vector<int> l(n), r(n);
  vector<ll> val(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> val[i];
    if (l[i] >= 0)
      l[i]--;
    if (r[i] >= 0)
      r[i]--;
  }
  vector<ll> node;
  function<void(int)> dfs = [&](int u) {
    if (l[u] != -1)
      dfs(l[u]);
    node.emplace_back(val[u]);
    if (r[u] != -1)
      dfs(r[u]);
  };
  dfs(0);
  ll lef = 1, rig = c, cnt = 0;
  ll ans = 1;
  for (auto i : node) {
    if (i == -1) {
      cnt++;
    } else {
      rig = i;
      ans = ans * C(cnt + rig - lef, cnt) % MOD;
      ans %= MOD;
      lef = i;
      cnt = 0;
    }
  }
  dbg(node);
  rig = c;
  ans = ans * C(cnt + rig - lef, cnt) % MOD;

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