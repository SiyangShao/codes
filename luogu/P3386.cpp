// n vertices left, m vertices right
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n, m, c;
  cin >> n >> m >> c;
  vector<vector<int>> E(n);
  for (int i = 0; i < c; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
  }
  vector<int> vis(m), link(m);
  fill(link.begin(), link.end(), -1);
  // find augmenting path, O(n) once
  function<bool(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        return true;
      }
    }
    return false;
  };
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    // dfs(i) x times means add x points same as point i in the map
    if (dfs(i)) {
      cnt++;
      fill(vis.begin(), vis.end(), 0);
    }
  }
  cout << cnt << "\n";
}