#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> mp(n, vector<int>(n));
  int l = 1, r = n * n;
  int stp = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; ++j) {
        if (stp % 2 == 0) {
          mp[i][j] = l;
          l++, stp++;
        } else {
          mp[i][j] = r;
          r--, stp++;
        }
      }
    } else {
      for (int j = n - 1; j >= 0; --j) {
        if (stp % 2 == 0) {
          mp[i][j] = l;
          l++, stp++;
        } else {
          mp[i][j] = r;
          r--, stp++;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << mp[i][j] << " ";
    cout << "\n";
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
