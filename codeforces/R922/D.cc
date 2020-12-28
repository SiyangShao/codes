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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + a[i];
  }
  function<bool(ll)> check = [&](ll x) {
    multiset<ll> ms;
    vector<ll> dp(n + 1);
    int j = -1;
    ms.emplace(0);
    for (auto i : ranges::views::iota(0, n + 1)) {
      while (j < i) {
        if (pre[i] - pre[j + 1] > x) {
          ms.extract(j == -1 ? 0 : dp[j]);
          j++;
        } else {
          break;
        }
      }
      dp[i] = *ms.begin() + (i < n ? a[i] : 0);
      ms.emplace(dp[i]);
    }
    ll mi = dp.back();
    for (auto i : ranges::views::iota(0, n) | ranges::views::reverse) {
      if (pre[n] - pre[i + 1] <= x) {
        mi = min(mi, dp[i]);
      } else {
        break;
      }
    }
    return mi > x;
  };
  cout << *ranges::partition_point(ranges::views::iota(0LL, (ll)1e16), check)
       << "\n";
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