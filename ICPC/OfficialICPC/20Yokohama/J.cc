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
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<int> nuts(n, 0);
  for (int i = 0; i < m; ++i) {
    int u;
    cin >> u;
    u--;
    nuts[u] = 1;
  }
  vector<int> vis(n, 0);
  function<void(int, int, int)> dfs = [&](int u, int fa, int have_nuts) {
    if (!have_nuts) {
      assert(nuts[u] == 0);
      vis[u] = 1;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u, nuts[v]);
      }
      return;
    }
    int empty_next = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      if (!nuts[v])
        empty_next++;
    }
    if (empty_next == 0) {
      return;
    } else if (empty_next == 1) {
      vis[u] = 1;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u, 1);
      }
    } else {
      vis[u] = 1;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u, nuts[v]);
      }
    }
  };
  dfs(0, 0, 0);
  cout << accumulate(vis.begin(), vis.end(), 0) << "\n";
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