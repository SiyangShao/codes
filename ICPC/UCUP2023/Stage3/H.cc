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
  int n, m;
  cin >> n >> m;
  vector<int> deg(n, n - 1);
  vector<unordered_set<int>> revE(n);
  vector<pair<int, int>> edg;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]--, deg[v]--;
    edg.emplace_back(u, v);
    revE[u].emplace(v);
    revE[v].emplace(u);
  }
  vector<ll> ans(n, 0);
  ll not_edg = 0;
  for (auto [u, v] : edg) {
    if (deg[u] * 2 < n || deg[v] * 2 < n)
      continue;
    not_edg++;
  }
  ll large_node = 0;
  for (int u = 0; u < n; ++u) {
    if (deg[u] * 2 >= n) {
      large_node++;
    }
  }
  ans[1] += large_node * (large_node - 1) - not_edg * 2;
  ans[2] += not_edg * 2;
  function<void(int)> bfs = [&](int s) {
    queue<pair<int, int>> Q;
    Q.emplace(s, 0);
    unordered_set<int> unvisited;
    for (int i = 0; i < n; ++i) {
      if (i != s)
        unvisited.emplace(i);
    }
    while (!Q.empty()) {
      auto [u, d] = Q.front();
      if (deg[u] * 2 >= n)
        ans[d] += 2;
      else
        ans[d]++;
      Q.pop();
      auto it = unvisited.begin();
      while (it != unvisited.end()) {
        if (revE[u].contains(*it)) {
          it = next(it);
        } else {
          auto cur = it;
          Q.emplace(*it, d + 1);
          it = next(it);
          unvisited.erase(cur);
        }
      }
    }
  };
  for (int u = 0; u < n; ++u) {
    if (deg[u] * 2 < n) {
      bfs(u);
    }
  }
  dbg(ans);
  for (int i = 1; i < n; ++i) {
    cout << ans[i] / 2 << " ";
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