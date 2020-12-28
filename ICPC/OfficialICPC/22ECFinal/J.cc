#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  for (int i = 0; i < n; ++i) {
    if ((int)E[i].size() == n - 1) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> num(n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if ((int)E[i].size() == 1) {
      num[E[i][0]]++;
      cnt++;
    }
  }
  sort(num.begin(), num.end(), greater<>());
  cout << max(num[0], (cnt + 1) / 2) << "\n";
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