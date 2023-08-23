#include <bits/stdc++.h>
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
  vector<int> dp(n);
  dp[0] = 1;
  int cur = 0;
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1];
    if (cur < n && a[cur] >= dp[i] + 1) {
      dp[i]++;
    } else {
      cur++;
    }
  }
  for (auto i : dp) {
    cout << i << " ";
  }
  cout << "\n";
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