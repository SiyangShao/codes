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
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> mx(n), nxt(n, -1);
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      if (nxt[u] == -1 || mx[v] > mx[nxt[u]]) {
        nxt[u] = v;
      }
    }
    if (nxt[u] == -1) {
      mx[u] = 1;
    } else {
      mx[u] = mx[nxt[u]] + 1;
    }
  };
  dfs(0, 0);
  int l = 0, r = 0;
  while (nxt[r] != -1) {
    r = nxt[r];
  }
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