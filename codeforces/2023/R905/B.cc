#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
auto solve() {
  int n, t;
  cin >> n >> t;
  vector<vector<pair<int, int>>> E(n);
  for (int j = 0; j < t; ++j) {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      E[u].emplace_back(v, j);
      E[v].emplace_back(u, j);
    }
  }
  int k;
  cin >> k;
  vector<int> a(k);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<vector<int>> id(t);
  for (int i = 0; i < k; ++i) {
    id[a[i]].emplace_back(i);
  }
  vector<int> vis(n, 0), dis(n, inf);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
  dis[0] = 0;
  Q.emplace(dis[0], 0);
  while (!Q.empty()) {
    auto [_, u] = Q.top();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, w] : E[u]) {
      auto it = lower_bound(id[w].begin(), id[w].end(), dis[u]);
      if (it == id[w].end())
        continue;
      int dv = *it + 1;
      if (dis[v] > dv) {
        dis[v] = dv;
        Q.emplace(dis[v], v);
      }
    }
  }
  cout << (dis[n - 1] == inf ? -1 : dis[n - 1]) << "\n";
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