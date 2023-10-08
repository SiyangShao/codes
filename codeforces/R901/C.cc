#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
constexpr int N = 5000 + 5;
array<array<ld, N>, N> G;
void init() {
  for (int i = 1; i < N; i += 2) {
    for (int j = 1; j <= i; ++j) {
      G[i][j] = ld(1) / ld(i);
    }
  }
  for (int i = 2; i < N; i += 2) {
    G[i][1] = ld(1);
    for (int j = 1; j <= i; ++j) {
      G[i][j] /= i;
    }
    if (i + 2 < N) {
      for (int j = 1; j <= i; ++j) {
        G[i + 2][j + 1] += G[i][j] * (i - j + 1);
        G[i + 2][j + 2] += G[i][j] * j;
      }
    }
  }
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for ([[maybe_unused]] auto i : views::iota(0, m)) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
  }
  vector<ld> dp(n);
  dp[n - 1] = 1;
  function<void(int)> dfs = [&](int u) {
    ranges::sort(E[u], [&](int i, int j) { return dp[i] > dp[j]; });
    int deg = (int)E[u].size();
    int index = 1;
    for_each(E[u].begin(), E[u].end(), [&](int v) {
      dp[u] += dp[v] * G[deg][index];
      index++;
    });
  };
  for (auto u : views::iota(0, n - 1) | views::reverse) {
    dfs(u);
  }
  cout << fixed << setprecision(13) << dp[0] << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}