#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> add;
  vector<vector<int>> st(n, vector<int>(26, 0));
  for (int i = 1; i * i <= n; ++i) {
    if (n % i != 0)
      continue;
    int j = n / i;
    add.emplace_back(i);
    add.emplace_back(j);
  }

  for (int i = 0; i < n; ++i) {
    char ans = 0;
    for (int j = 0; j < 26; ++j) {
      if (st[i][j] == 0) {
        ans = 'a' + j;
        break;
      }
    }
    for (auto j : add) {
      if (i + j < n) {
        st[i + j][ans - 'a'] = 1;
      }
    }
    cout << ans;
  }
  cout << "\n";
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