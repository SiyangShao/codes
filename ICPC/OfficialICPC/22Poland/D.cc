#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  vector<int> siz(n), leaf(n, 0), dp(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  int num = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    siz[u] = 1;
    int lf = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      siz[u] += siz[v];
      lf += leaf[v];
    }
    if (lf == 0) {
      lf = 1;
      num++;
    }
    leaf[u] = lf;
    dp[siz[u]] += leaf[u];
  };
  dfs(0, 0);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] == num) {
      cnt++;
    }
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; ++i) {
    if (dp[i] == num) {
      cout << i << " ";
    }
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