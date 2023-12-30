#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
constexpr int inf = 1e6;
auto solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  std::vector<int> dp(n, inf), no_dp(n, inf);
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      if (dp[v] + 1 <= dp[u]) {
        no_dp[u] = std::min(no_dp[u], dp[u] - 1);
        no_dp[u] = std::min(no_dp[u], no_dp[v]);
        dp[u] = dp[v] + 1;
      } else {
        no_dp[u] = std::min(no_dp[u], dp[v]);
        no_dp[u] = std::min(no_dp[u], no_dp[v]);
      }
    }
    if (dp[u] == inf)
      dp[u] = 1;
  };
  dfs(0, -1);
  dbg(dp, no_dp);
  int cnt = 0;
  std::function<void(int, int)> change_root = [&](int u, int fa) {
    dbg(u, dp, no_dp);
    cnt = std::max(cnt, dbg(std::min(dp[u], no_dp[u])));
    std::multiset<int> can, cannot;
    for (auto v : E[u]) {
      can.emplace(dp[v]);
      cannot.emplace(no_dp[v]);
    }
    can.emplace(inf), cannot.emplace(inf);
    can.emplace(inf), cannot.emplace(inf);
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      // change root from u to v
      const int a = dp[u], b = no_dp[u], c = dp[v], d = no_dp[v];
      // update node u
      can.erase(can.find(c)), cannot.erase(cannot.find(d));
      dp[u] = *can.begin() + 1;
      if (dp[u] >= n)
        dp[u] = 1;
      no_dp[u] = std::min(*next(can.begin()), *cannot.begin());
      if (dp[v] == 1) {
        dp[v] = dp[u] + 1;
        no_dp[v] = no_dp[u];
      } else if (dp[v] >= dp[u] + 1) {
        no_dp[v] = std::min(no_dp[v], dp[v] - 1);
        no_dp[v] = std::min(no_dp[v], no_dp[u]);
        dp[v] = dp[u] + 1;
      } else {
        no_dp[v] = std::min(no_dp[v], dp[u]);
        no_dp[v] = std::min(no_dp[v], no_dp[u]);
      }
      change_root(v, u);
      // change back
      dp[u] = a, no_dp[u] = b, dp[v] = c, no_dp[v] = d;
      can.emplace(c), cannot.emplace(d);
    }
  };
  change_root(0, -1);
  std::cout << cnt << "\n";
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  while (_--) {
    solve();
  }
}