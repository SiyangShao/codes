#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int m, n;
  cin >> m >> n;
  vector a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        a[i][j] = 1e9 + 7;
      }
    }
  }
  vector dp(m, vector<int>(m, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int r = 0; r < n; ++r) {
        if (a[r][i] < a[r][j]) {
          dp[i][j]++;
        } else if (a[r][i] > a[r][j]) {
          dp[j][i]++;
        }
      }
    }
  }
  vector path(m, vector<int>(m, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == j) {
        path[i][j] = 1e9 + 7;
        continue;
      }
      if (dp[i][j] == dp[j][i]) {
        path[i][j] = path[j][i] = 0;
      } else if (dp[i][j] < dp[j][i]) {
        path[i][j] = 0;
        path[j][i] = dp[j][i];
      } else {
        path[j][i] = 0;
        path[i][j] = dp[i][j];
      }
    }
  }
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        path[i][j] = max(path[i][j], min(path[i][k], path[k][j]));
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    bool mx = true;
    for (int j = 0; j < m; ++j) {
      if (i == j)
        continue;
      if (path[i][j] < path[j][i]) {
        mx = false;
        break;
      }
    }
    if (mx) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
}