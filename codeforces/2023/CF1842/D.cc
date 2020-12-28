#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector dis(n, vector<ll>(n, inf));
  for (int i = 0; i < n; ++i) {
    dis[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    dis[u][v] = min(dis[u][v], w);
    dis[v][u] = min(dis[v][u], w);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  if (dis[0][n - 1] >= inf) {
    cout << "inf\n";
    return;
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::stable_sort(id.begin(), id.end(),
                      [&](int i, int j) { return dis[0][i] < dis[0][j]; });
  vector<int> vis(n, 0);
  cout << dis[0][n - 1] << " ";
  for (int i = 0; i < n; ++i) {
    if (id[i] == n - 1) {
      cout << i << "\n";
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (id[i] == n - 1)
      break;
    vis[id[i]] = 1;
    for (int j = 0; j < n; ++j) {
      cout << vis[j];
    }
    cout << " ";
    cout << dis[0][id[i + 1]] - dis[0][id[i]] << "\n";
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