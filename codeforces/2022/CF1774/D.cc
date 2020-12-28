#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n, vector<int>(m));
  vector<set<int>> has(n);
  int num = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> E[i][j];
      num += E[i][j];
      if (E[i][j] == 1) {
        has[i].emplace(j);
      }
    }
  }
  if (num % n != 0) {
    cout << "-1\n";
    return;
  }
  num /= n;
  vector<pair<int, int>> large, small;
  for (int i = 0; i < n; ++i) {
    int sum = accumulate(E[i].begin(), E[i].end(), 0);
    if (sum > num) {
      large.emplace_back(i, sum - num);
    } else if (sum < num) {
      small.emplace_back(i, num - sum);
    }
  }
  vector<tuple<int, int, int>> ans;
  while (!large.empty() && !small.empty()) {
    auto x = large.back(), y = small.back();
    large.pop_back(), small.pop_back();
    int u = x.first, v = y.first;
    vector<int> del;
    for (auto i : has[u]) {
      if (x.second == 0 || y.second == 0)
        break;
      if (!has[v].contains(i)) {
        has[v].emplace(i);
        del.emplace_back(i);
        ans.emplace_back(u, v, i);
        x.second--, y.second--;
      }
    }
    for (auto i : del) {
      has[u].erase(i);
    }
    if (x.second != 0) {
      large.emplace_back(x);
    }
    if (y.second != 0) {
      small.emplace_back(y);
    }
  }
  cout << ans.size() << "\n";
  for (auto &[x, y, z] : ans) {
    x++, y++, z++;
    cout << x << " " << y << " " << z << "\n";
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