#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  if (m >= n * 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<vector<int>> ans(n * 2, vector<int>(m, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2 * n; j += 2) {
      ans[(j + i) % (n * 2)][i] = j / 2 + 1;
      ans[(j + i + 1) % (n * 2)][i] = j / 2 + 1;
    }
  }
  for (int i = 0; i < n * 2; i++) {
    for (auto j : ans[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
