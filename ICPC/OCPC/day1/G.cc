#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n;
  cin >> n;
  vector<string> mp(n);
  for (auto &i : mp)
    cin >> i;
  vector<int> E(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == '1') {
        E[i] |= 1 << j;
      }
    }
  }
  const int msk = (1 << n);
  const int lst = (1 << (n - 1));
  vector<int> dp(msk, 0);
  dp[lst] = lst;
  for (int i = lst; i < msk; ++i) {
    for (int v = 0; v < n; ++v) {
      if ((i >> v) & 1) {
        // for (int u = n - 1; u < n; ++u) {
        if (dp[i - (1 << v)] & E[v]) {
          dp[i] |= (1 << v);
        }
        // }
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     if ((dp[msk - 1][i] >> j) & 1) {
  //       cout << 1;
  //     } else {
  //       cout << 0;
  //     }
  //   }
  //   cout << "\n";
  // }
  vector<int> ans(n, 0);
  ans[n - 1] = dp[msk - 1];
  for (int i = 0; i < lst; ++i) {
    // i is mask u
    int j = msk - 1 - i;
    for (int u = 0; u + 1 < n; ++u) {
      if ((dp[i | lst] >> u) & 1)
        ans[u] = ans[u] | dp[j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((ans[i] >> j) & 1) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << "\n";
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