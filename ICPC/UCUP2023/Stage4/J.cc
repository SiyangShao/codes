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
  int n, k;
  cin >> n >> k;
  vector<ll> w(n), s(k);
  for (auto &i : w)
    cin >> i;
  for (auto &i : s)
    cin >> i;
  auto ord = w, rev = w;
  ranges::reverse(rev.begin(), rev.end());
  for (int i = 1; i < n; ++i) {
    ord[i] += ord[i - 1];
    rev[i] += rev[i - 1];
  }
  vector dp(k, vector<int>(n));

  for (int cur = 0; cur < k; ++cur) {
    for (int l = 0; l < n; ++l) {
      if (cur != 0) {
        dp[cur][l] = dp[cur - 1][l];
      } else {
        dp[cur][l] = l;
      }
      // find right
      int cur_r = dp[cur][l];
      auto it = prev(upper_bound(ord.begin(), ord.end(), ord[cur_r] + s[cur]));
      dp[cur][l] = max(dp[cur][l], (int)(it - ord.begin()));
      // find lef
      it = prev(upper_bound(rev.begin(), rev.end(), rev[n - l - 1] + s[cur]));
      int nxt_l = (int)(rev.end() - it) - 1;
      assert(nxt_l <= l);
      dp[cur][nxt_l] = max(dp[cur][nxt_l], dp[cur][l]);
    }
  }
  if (dp[k - 1][0] == n - 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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