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
  int n, k;
  cin >> n >> k;
  k *= 2;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<int> dis(n);
  int cnt = 1;
  function<void(int, int)> dfs = [&](int u, int fa) {
    dis[u] = 0;
    vector<int> son;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      if (dis[v] + 1 > k) {
        cnt++;
      } else {
        son.emplace_back(dis[v] + 1);
      }
    }
    if (son.empty()) {
      return;
    }
    sort(son.begin(), son.end());
    while (static_cast<int>(son.size()) >= 2) {
      int fi = son[son.size() - 1];
      int se = son[son.size() - 2];
      if (fi + se > k) {
        son.pop_back();
        cnt++;
      } else {
        break;
      }
    }
    if (!son.empty()) {
      dis[u] = son.back();
    }
  };
  dfs(0, 0);
  cout << cnt << "\n";
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