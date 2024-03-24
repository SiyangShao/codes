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
  for (auto &i : a)
    cin >> i;
  vector<int> dp(n);
  int lst = n;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 1) {
      lst = i;
      break;
    }
  }
  dp[lst] = 0;
  for (int i = lst - 1; i >= 0; --i) {
    if (a[i] == 0) {
      dp[i] = dp[i + 1] + 1;
    } else {
      dp[i] = dp[i + 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      cout << dp[i] << "\n";
      return;
    }
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