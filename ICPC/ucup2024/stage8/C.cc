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
  int k;
  cin >> k;
  int n = (k + 2) * 2;
  vector<pair<int, int>> edg;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) {
      for (int j = 1; j + 1 < i; j += 2) {
        edg.emplace_back(i, j);
      }
    } else {
      for (int j = 2; j < i; j += 2) {
        edg.emplace_back(i, j);
      }
    }
  }
  cout << n << " " << edg.size() << " " << 2 << "\n";
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0)
      cout << "2 ";
    else
      cout << "1 ";
  }
  cout << "\n";
  for (auto [u, v] : edg) {
    cout << u << " " << v << "\n";
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