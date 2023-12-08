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
  int n, m, k;
  cin >> n >> m >> k;
  int len = n - 1 + m - 1;
  if (k < len || (k - len) % 2 == 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<vector<int>> hen(n, vector<int>(m - 1, 0));
  vector<vector<int>> zong(n - 1, vector<int>(m, 0));
  zong[0][1] = 1;
  for (int i = 1; i < n - 1; i += 2) {
    zong[i][0] = 1;
  }
  for (int i = 0; i < m - 1; i++) {
    if (zong[n - 2][0] == 0) {
      if (i % 2 == 0) {
        hen[n - 1][i] = 1;
      } else {
        hen[n - 1][i] = 0;
      }
    } else {
      if (i % 2 == 1) {
        hen[n - 1][i] = 1;
      } else {
        hen[n - 1][i] = 0;
      }
    }
  }
  hen[n - 2][m - 2] = hen[n - 1][m - 2];
  if (hen[n - 1][m - 2] == 0) {
    zong[n - 2][m - 1] = 1;
    zong[n - 2][m - 2] = 1;
  } else {
    zong[n - 2][m - 1] = 0;
    zong[n - 2][m - 2] = 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      cout << (hen[i][j] ? 'R' : 'B') << " ";
    }
    cout << "\n";
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << (zong[i][j] ? 'R' : 'B') << " ";
    }
    cout << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}