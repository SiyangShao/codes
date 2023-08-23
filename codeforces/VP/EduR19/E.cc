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
  int blk = (int)sqrt(n);
  int q;
  cin >> q;
  vector<int> ans(q);
  vector<vector<pair<int, int>>> query(blk);
  function<int(int, int)> cal = [&](int p, int k) {
    if (p > n)
      return 0;
    return cal(p + a[p] + k, k) + 1;
  };
  for (int i = 0; i < q; ++i) {
    int p, k;
    cin >> p >> k;
    if (k >= blk) {
      ans[i] = cal(p, k);
    } else {
      query[k].emplace_back(p, i);
    }
  }
  vector<int> dp(n + 1, 0);
  for (int k = 1; k < blk; ++k) {
    for (int j = n; j >= 1; --j) {
      if (j + a[j] + k > n) {
        dp[j] = 1;
      } else {
        dp[j] = dp[j + a[j] + k] + 1;
      }
    }
    for (auto &[p, i] : query[k]) {
      ans[i] = dp[p];
    }
  }
  for (auto i : ans) {
    cout << i << "\n";
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