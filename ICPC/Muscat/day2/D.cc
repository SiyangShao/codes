#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n;
  cin >> n;
  vector<int> fa(n, 0);
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    cin >> fa[i];
    fa[i]--;
    E[fa[i]].emplace_back(i);
  }
  vector<ll> c(n);
  for (auto &i : c)
    cin >> i;
  map<pair<int, ll>, ll> mp;
  function<ll(int, ll)> dfs = [&](int u, ll x) {
    if (mp.contains({u, x}))
      return mp[{u, x}];
    if (E[u].empty()) {
      return x * c[u];
    }
    ll ans = 0, mx = inf;
    for (auto v : E[u]) {
      ll val1 = dfs(v, c[u]);
      ll val2 = dfs(v, x);
      ans += val1;
      mx = min(mx, val2 - val1);
    }
    return mp[{u, x}] = ans + mx;
  };
  ll ans = 0;
  for (auto v : E[0]) {
    ans += dfs(v, c[0]);
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