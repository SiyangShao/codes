#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using bst = bitset<2048>;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (auto &i : d)
    cin >> i;
  ranges::sort(d, greater<>());
  if (d[0] + d[1] > k) {
    cout << "NO\n";
    return;
  }
  bst x;
  x[d[0]] = true;
  for (int i = 1; i < n; ++i) {
    x |= x << d[i];
  }
  if (x[k]) {
    cout << "YES\n";
  } else {
    if (2 * d[0] > k) {
      cout << "NO\n";
      return;
    }
    vector<bst> dp(k + 1);
    dp[0][0] = true;
    for (int i = 1; i < n; ++i) {
      for (int j = k; j >= 0; --j) {
        if (j + d[i] <= k) {
          dp[j + d[i]] |= dp[j];
        }
        dp[j] |= (dp[j] << d[i]);
      }
    }
    for (int i = d[0]; i <= k - d[0]; ++i) {
      if (dp[i][k - i]) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
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