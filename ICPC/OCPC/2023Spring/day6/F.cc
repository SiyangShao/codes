#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) {
        cout << "3 ";
      } else if (i == n - 1 && j == n - 1) {
        cout << "3 ";
      } else if (abs(i - j) <= 1) {
        cout << "2 ";
      } else if (abs(i - j) == 2) {
        cout << "1 ";
      } else {
        cout << "0 ";
      }
    }
    cout << "\n";
  }
  cout << "\n";
  vector mp(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    mp[i][i] = 1;
    if (i % 2 == 1) {
      if (i - 1 >= 0)
        mp[i][i - 1] = 1;
      if (i + 1 < n)
        mp[i][i + 1] = 1;
    }
    for (auto j : mp[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  for (int i = 0; i < n; ++i) {
    fill(mp[i].begin(), mp[i].end(), 0);
  }
  for (int i = 0; i < n; ++i) {
    mp[i][i] = 1;
    if (i % 2 == 1) {
      if (i - 1 >= 0)
        mp[i - 1][i] = 1;
      if (i + 1 < n)
        mp[i + 1][i] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mp[i][j] << " ";
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