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
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  ll ans = 0;
  vector<ll> dp(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    ll mul = 1, add = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      mul = mul * (dp[v] + 1) % MOD;
      add = (add + dp[v]) % MOD;
    }
    dp[u] = mul;
    ans = (ans + add) % MOD;
    dbg(dp[u]);
  };
  dfs(0, 0);
  ans = (ans + 1 + dp[0]) % MOD;
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