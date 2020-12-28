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
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R')
      a[i] = 0;
    else if (s[i] == 'G')
      a[i] = 1;
    else
      a[i] = 2;
  }
  vector dp(n, vector<ll>(3, n));
  vector pre(n, vector<ll>(3, -1));
  for (int i = 0; i < 3; ++i) {
    if (a[0] == i) {
      dp[0][i] = 0;
    } else {
      dp[0][i] = 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) +
                 (a[i] == j ? 0 : 1);
      if (dp[i - 1][(j + 1) % 3] < dp[i - 1][(j + 2) % 3]) {
        pre[i][j] = (j + 1) % 3;
      } else {
        pre[i][j] = (j + 2) % 3;
      }
    }
  }
  ll ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  ll lst = -1;
  if (dp[n - 1][0] == ans) {
    lst = 0;
  } else if (dp[n - 1][1] == ans) {
    lst = 1;
  } else {
    lst = 2;
  }
  vector<ll> b;
  b.emplace_back(lst);
  for (int i = n - 1; i > 0; --i) {
    lst = pre[i][lst];
    b.emplace_back(lst);
  }
  cout << ans << "\n";
  reverse(b.begin(), b.end());
  for (auto i : b) {
    if (i == 0)
      cout << "R";
    else if (i == 1)
      cout << "G";
    else
      cout << "B";
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