#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  p[0] = -1;
  vector<vector<ll>> E(n);
  for (ll i = 1; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    E[p[i]].emplace_back(i);
  }
  vector<ll> dp(n), dep(n);
  // dp[n]: Longest non-decreasing subsequence end with point n
  // 2 selections: Combine all children (sum of all dp[u])
  // Or depth (add at the end of the longest chain)
  function<void(ll)> dfs = [&](ll u) {
    dp[u] = 0;
    dep[u] = 1;
    for (auto v : E[u]) {
      dfs(v);
      dep[u] = max(dep[u], dep[v] + 1);
      dp[u] += dp[v];
    }
    dp[u] = max(dp[u], dep[u]);
  };
  dfs(0);
  cout << dp[0] << "\n";
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