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
    int u;
    cin >> u;
    u--;
    E[u].emplace_back(i);
  }
  vector<int> dep(n);
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      dfs(v);
      dep[u] = max(dep[u], dep[v] + 1);
    }
  };
  dfs(0);
  vector<int> num(n);
  for (int i = 0; i < n; ++i) {
    int j;
    cin >> j;
    if (j) {
      num[dep[i]]++;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (num[i] % 2 == 1) {
      cout << "First\n";
      return;
    }
  }
  cout << "Second\n";
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