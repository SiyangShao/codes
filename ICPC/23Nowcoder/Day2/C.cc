#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u][v]++;
    G[v][u]++;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (G[i][j] % 2 == 1) {
        E[i].push_back(j);
      }
    }
  }
  vector<int> col(n, -1);
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (col[v] == -1) {
        col[v] = col[u] ^ 1;
        dfs(v);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (col[i] == -1) {
      col[i] = 0;
      dfs(i);
    }
  }
  for (auto i : col) {
    cout << i << " ";
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