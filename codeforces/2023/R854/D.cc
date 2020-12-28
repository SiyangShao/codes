#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<ll> cold(k), hot(k);
  for (auto &i : cold)
    cin >> i;
  for (auto &i : hot)
    cin >> i;
  vector<ll> dp(n, inf);
  vector<ll> presum(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    presum[i + 1] =
        presum[i] + ((i && a[i] == a[i - 1]) ? hot[a[i]] : cold[a[i]]);
  }
  dp[0] = cold[a[0]];
  vector<ll> lst(k, inf);
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1] + ((a[i] == a[i - 1]) ? hot[a[i]] : cold[a[i]]);
    dp[i] = min(dp[i], lst[a[i]] + presum[i] + hot[a[i]]);
    lst[a[i - 1]] = min(lst[a[i - 1]], dp[i] - presum[i + 1]);
  }
  dbg(dp, lst);
  cout << dp.back() << "\n";
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}