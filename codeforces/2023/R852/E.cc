#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  vector<int> dp(n + 1), pre(n + 1);
  // dp[i]: total segment for the first ith element
  // pre[i]: segment from 1 to i for the first ith element
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= i) {
      pre[i] = max(pre[i - a[i]] + 1, pre[i - 1]);
    } else {
      pre[i] = pre[i - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= i) {
      dp[i] = pre[i - a[i]] + n - i + 1;
    } else {
      dp[i] = n - a[i] + 1;
    }
  }
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[dp[i]] = i;
  }
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    cout << ans[k] << "\n";
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