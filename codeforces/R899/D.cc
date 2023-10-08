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
  vector<int> a(n), val(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> E(n);
  vector<ll> size(n);
  vector<ll> ans(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  for (int t = 0; t < 20; ++t) {
    for (int i = 0; i < n; ++i) {
      val[i] = (a[i] >> t) & 1;
    }
    vector<array<ll, 2>> dp(n, {inf, inf});
    function<void(int, int)> init = [&](int u, int fa) {
      size[u] = 1;
      dp[u][val[u]] = 0;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        init(v, u);
        size[u] += size[v];
        dp[u][val[u]] += dp[v][val[u]];
      }
      dp[u][!val[u]] = dp[u][val[u]] + size[u];
    };
    init(0, 0);
    // dbg(dp);
    function<void(int, int)> transfer = [&](int u, int fa) {
      ans[u] += (1LL << t) * min(dp[u][0], dp[u][1]);
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        ll x1 = dp[u][0], y1 = dp[u][1], x2 = dp[v][0], y2 = dp[v][1];
        ll z1 = size[u], z2 = size[v];
        size[u] -= size[v];
        dp[u][val[u]] -= dp[v][val[u]];
        dp[u][!val[u]] = dp[u][val[u]] + size[u];
        dp[v][val[v]] += dp[u][val[v]];
        size[v] += size[u];
        dp[v][!val[v]] = dp[v][val[v]] + size[v];
        transfer(v, u);
        dp[u][0] = x1, dp[u][1] = y1, dp[v][0] = x2, dp[v][1] = y2;
        size[u] = z1, size[v] = z2;
      }
    };
    transfer(0, 0);
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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