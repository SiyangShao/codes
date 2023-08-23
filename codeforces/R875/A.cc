#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v, i);
    E[v].emplace_back(u, i);
  }
  vector<int> dp(n, n);
  dp[0] = 0;
  function<void(int, int, int)> dfs = [&](int u, int fa, int in) {
    for (auto [v, id] : E[u]) {
      if (v == fa)
        continue;
      if (id < in) {
        dp[v] = min(dp[v], dp[u] + 1);
      } else {
        dp[v] = min(dp[v], dp[u]);
      }
      dfs(v, u, id);
    }
  };
  dfs(0, -1, n + 1);
  // for(int i = 0 ; i < n ; ++ i)
  //   cout << dp[i] << " ";
  // cout << "\n";
  cout << *max_element(dp.begin(), dp.end()) << "\n";
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