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
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<int> ans(n, 0);
  vector<int> id(n, 0);
  iota(id.begin(), id.end(), 0);
  for (int root = 0; root < n; ++root) {
    vector<int> dis(n, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
      }
    };
    dfs(root, root);
    sort(id.begin(), id.end(), [&](int u, int v) { return dis[u] < dis[v]; });
    assert(id[0] == root);
    int pre_sum = 0;
    for (int i = 0; i < n; ++i) {
      pre_sum += dis[id[i]] * 2;
      ans[i] = max(ans[i], (i + 1) * (n - 1) - pre_sum);
    }
  }
  cout << "0";
  for (auto i : ans) {
    cout << " " << i;
  }
  cout << "\n";
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