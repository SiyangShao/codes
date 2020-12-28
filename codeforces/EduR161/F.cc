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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector f(n, vector(n, vector<int>(x, n)));
  vector g(n, vector(n, vector<int>(x, n)));
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < x; ++k) {
      f[i][i][k] = a[i] == k;
      g[i][i][k] = a[i] != k;
    }
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 0, r = len - 1; r < n; l++, r++) {
      for (int mid = l; mid < r; ++mid) {
        for (int k = 0; k < x; ++k) {
          f[l][r][k] = min(f[l][r][k], f[l][mid][k] + f[mid + 1][r][k]);
          g[l][r][k] = min(g[l][r][k], g[l][mid][k] + g[mid + 1][r][k]);
        }
      }
      int mn = n, se = n;
      for (int k = 0; k < x; ++k) {
        g[l][r][k] = min(g[l][r][k], f[l][r][k] + 1);
        if (g[l][r][k] < mn) {
          se = exchange(mn, g[l][r][k]);
        } else {
          se = min(se, g[l][r][k]);
        }
      }
      for (int k = 0; k < x; ++k) {
        f[l][r][k] = min(f[l][r][k], g[l][r][k] == mn ? se : mn);
      }
    }
  }
  cout << ranges::min(g[0][n - 1]) << "\n";
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