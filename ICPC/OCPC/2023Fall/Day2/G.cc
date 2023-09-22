#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  vector<vector<int>> ans(n);
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '1' && mp[i - 1][j] == '1') {
        ans[i].emplace_back(j);
      }
    }
    int pre = -2;
    for (auto j : ans[i]) {
      if (j != pre + 1) {
        sum++;
      }
      pre = j;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (mp[i][j] == '1' && mp[i][j - 1] == '1') {
        sum++;
      }
    }
  }
  // cout << sum << "\n";
  cout << (sum % 2 == 0 ? "Slavko" : "Mirko") << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}