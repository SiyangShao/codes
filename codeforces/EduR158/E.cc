#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  constexpr ll inf = 1e16;

  vector dp(n, -inf);
  ll ans = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    vector choose(4, -inf);
    choose[0] = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      for (int i = 3; i >= 0; --i) {
        choose[min(i + 1, 3)] = max(choose[min(i + 1, 3)], choose[i] + dp[v]);
      }
    }
    for (int i = 0; i < 4; ++i) {
      if (i == 1)
        dp[u] = max(dp[u], choose[i]);
      else
        dp[u] = max(dp[u], choose[i] + a[u]);
      if (i == 2)
        ans = max(ans, choose[i]);
      else
        ans = max(ans, choose[i] + a[u]);
    }
  };
  dfs(0, 0);
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