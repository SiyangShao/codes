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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> MEX(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    vector<int> vis(n + 2, 0);
    int mex = 0;
    for (int j = i; j < n; ++j) {
      vis[a[j]]++;
      while (vis[mex])
        mex++;
      MEX[i][j] = mex;
    }
  }
  int max_mex = MEX[0][n - 1];
  max_mex = [&](int u) {
    for (int i = 0;; i++) {
      if ((1 << i) > u)
        return (1 << i);
    }
    return -1;
  }(max_mex);
  assert(max_mex != -1);
  dbg(max_mex);
  vector<vector<bool>> dp(n + 1, vector<bool>(max_mex, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < max_mex; ++j) {
      dp[i][j] = dp[i - 1][j];
    }
    int pre = 0;
    for (int j = i; j >= 1; --j) {
      if (j != i && a[j - 1] == a[i - 1]) {
        break;
      }
      int mex = MEX[j - 1][i - 1];
      if (mex != pre && mex > a[i - 1]) {
        for (int k = 0; k < max_mex; ++k) {
          if (dp[j - 1][k])
            dp[i][k ^ mex] = true;
        }
      }
      pre = mex;
    }
  }
  for (int i = max_mex - 1; i >= 0; --i) {
    if (dp[n][i]) {
      cout << i << "\n";
      return;
    }
  }
  cout << "-1\n";
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