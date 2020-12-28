#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp)
    cin >> i;
  vector matrix(n, vector<int>(m, 0));
  auto ans = matrix;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      matrix[i][j] = mp[i][j] == 'W' ? 0 : 1;
      int cnt = 0;
      for (auto [dx, dy] :
           vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
        int x = i + dx, y = j + dy;
        if (x >= 0 && x < n && y >= 0 && y < m) {
          cnt++;
        }
      }
      if (cnt % 2 == matrix[i][j]) {
        ans[i][j] = 2;
      } else {
        ans[i][j] = 3;
      }
    }
  }
  cout << "1\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j];
    }
    cout << "\n";
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