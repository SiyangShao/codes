#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
    i--;
  }
  vector<vector<int>> stp(k);
  for (int i = 0; i < k; ++i) {
    stp[i].emplace_back(0);
  }
  for (int i = 0; i < n; ++i) {
    stp[c[i]].emplace_back(i + 1);
  }
  for (int i = 0; i < k; ++i) {
    stp[i].emplace_back(n + 1);
  }
  int ans = n;
  for (int i = 0; i < k; ++i) {
    vector<int> cross;
    for (int j = 1; j < (int)stp[i].size(); ++j) {
      cross.emplace_back(stp[i][j] - stp[i][j - 1] - 1);
    }
    // for (auto j : cross) {
    //   cout << j << " ";
    // }
    // cout << "\n";
    auto mx = max_element(cross.begin(), cross.end());
    ans = min(ans, *mx);
    *mx = *mx / 2;
    mx = max_element(cross.begin(), cross.end());
    ans = min(ans, *mx);
  }
  cout << ans << "\n";
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