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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n + m);
  for (int i = 0; i < n + m; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<array<int, 2>> dp(n + m);
  function<void(int, int)> dfs = [&](int u, int fa) {
    dp[u][1] = 1;
    dp[u][0] = 0;
    for (auto v : E[u]) {
      if (v < n)
        continue;
      if (v == fa)
        continue;
      dfs(v, u);
      dp[u][1] += min(dp[v][0], dp[v][1]);
      dp[u][0] += dp[v][1];
    }
  };
  vector<int> col(n, 0);
  for (int i = 0; i < n; ++i) {
    dfs(i, i);
    if (dp[i][1] <= dp[i][0]) {
      col[i] = 1;
    }
    assert(dp[i][1] <= dp[i][0] + 1);
  }
  int rt = -1;
  for (int i = 0; i < n; ++i) {
    if (col[i] == 1) {
      rt = i;
      break;
    }
  }
  if (rt == -1) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += dp[i][0];
    }
    ans += (n + 1) / 2;
    cout << ans << "\n";
    return;
  }
  vector<int> ans;
  function<void(int, int)> getCircle = [&](int u, int fa) {
    if (u == rt) {
      if (!ans.empty())
        return;
    }
    ans.emplace_back(u);
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (v >= n)
        continue;
      getCircle(v, u);
      return;
    }
  };
  getCircle(rt, rt);
  assert((int)ans.size() == n);
  for (int i = 1; i < n; ++i) {
    int u = ans[i], pre = ans[i - 1];
    if (col[pre] == 0 && col[u] == 0) {
      col[u] = 1;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += dp[i][col[i]];
  }
  cout << sum << "\n";
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