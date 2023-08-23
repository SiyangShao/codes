#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  vector<set<int>> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i].emplace(i + 1);
  }
  vector<vector<int>> E(n);
  vector<int> in(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == '1') {
        E[i].emplace_back(j);
        in[j]++;
      }
    }
  }
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      in[v]--;
      for (auto i : ans[u]) {
        ans[v].emplace(i);
      }
      if (in[v] == 0) {
        in[v] = -1;
        dfs(v);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      in[i] = -1;
      dfs(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i].size();
    for (auto &j : ans[i]) {
      cout << " " << j;
    }
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
