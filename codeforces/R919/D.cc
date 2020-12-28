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
  int n, q;
  cin >> n >> q;
  vector<ll> lst(n + 1), dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    int a, v;
    cin >> a >> v;
    if (a == 1) {
      lst[i] = v;
      dp[i] = dp[i - 1] + 1;
    } else {
      lst[i] = lst[i - 1];
      dp[i] = ((v + 1) > ll(2e18) / dp[i - 1]) ? (ll)2e18 : dp[i - 1] * (v + 1);
    }
  }
  while (q--) {
    ll k;
    cin >> k;
    while (true) {
      ll pos = lower_bound(dp.begin(), dp.end(), k) - dp.begin();
      if (dp[pos] == k) {
        cout << lst[pos] << " ";
        break;
      }
      if (k % dp[pos - 1] == 0) {
        cout << lst[pos - 1] << " ";
        break;
      }
      k %= dp[pos - 1];
    }
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