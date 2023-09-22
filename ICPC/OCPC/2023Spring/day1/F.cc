#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e4;
constexpr ll M = N * N;
bitset<M> vis;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vis.reset();
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[v - n].emplace_back(u);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)E[i].size(); ++j) {
      for (int k = j + 1; k < (int)E[i].size(); ++k) {
        int u = E[i][j], v = E[i][k];
        if (u > v)
          swap(u, v);
        if (vis[u * n + v]) {
          cout << "2\n";
          return;
        }
        vis[u * n + v] = true;
      }
    }
  }
  cout << "3\n";
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