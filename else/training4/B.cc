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
  vector<pair<int, int>> edg;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
    edg.emplace_back(u, v);
  }
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
    i--;
  }
  int dif = 0;
  for (auto [u, v] : edg) {
    if (c[u] != c[v]) {
      dif++;
    }
  }
  for (int u = 0; u < n; ++u) {
    int cnt = 0;
    for (auto v : E[u]) {
      if (c[u] != c[v]) {
        cnt++;
      }
    }
    if (cnt == dif) {
      cout << "YES\n";
      cout << u + 1 << "\n";
      return;
    }
  }
  cout << "NO\n";
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