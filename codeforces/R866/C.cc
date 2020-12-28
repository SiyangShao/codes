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
  for (int u = 0; u < n; ++u) {
    if (E[u].size() < 3)
      continue;
    int cnt = 0;
    for (auto v : E[u]) {
      if (E[v].size() >= 2)
        cnt++;
    }
    if (cnt >= 3) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  vector<int> dis(n), pa(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dis[v] = dis[u] + 1;
      pa[v] = u;
      dfs(v, u);
    }
  };
  dfs(0, 0);
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (dis[x] < dis[i]) {
      x = i;
    }
  }
  fill(dis.begin(), dis.end(), 0);
  dfs(x, x);
  int y = 0;
  for (int i = 0; i < n; ++i) {
    if (dis[y] < dis[i]) {
      y = i;
    }
  }
  dbg(x, y);
  int cur = y;
  vector<vector<int>> ans(2);
  vector<int> vis(n);
  int flg = 0;
  pa[x] = -1;
  while (cur != x) {
    for (auto v : E[cur]) {
      if (vis[v])
        continue;
      if (pa[v] != cur)
        continue;
      ans[flg^1].emplace_back(v);
    }
    ans[flg].emplace_back(cur);
    vis[cur] = 1;
    cur = pa[cur];
    flg ^= 1;
  }
  dbg(pa);
  ans[flg].emplace_back(cur);
  reverse(ans[flg].begin(), ans[flg].end());
  for (auto u : ans[flg]) {
    cout << u + 1 << " ";
  }
  for (auto u : ans[flg ^ 1]) {
    cout << u + 1 << " ";
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