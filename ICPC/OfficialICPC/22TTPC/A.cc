#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<array<ll, 2>> dp(n);
  vector<vector<int>> E(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  function<void(int, int)> dfs = [&](int u, int fa) {
    if (a[u]) {
      dp[u][0] = 1;
      dp[u][1] = 0;
    } else {
      dp[u][0] = 0;
      dp[u][1] = 1;
    }
    vector<int> dif;
    ll base = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      base += dp[v][0];
      dif.emplace_back(dp[v][1] - dp[v][0]);
    }
    if (dif.empty())
      return;
    sort(dif.begin(), dif.end(), greater<>());
    // odd part
    dp[u][1] += base + dif[0];
    ll cnt = 0, sum = 0;
    for (int i = 1; i < (int)dif.size(); i += 2) {
      if (i + 1 >= (int)dif.size())
        break;
      sum += dif[i] + dif[i + 1];
      cnt = max(cnt, sum);
    }
    dp[u][1] += cnt;
    cnt = 0, sum = 0;
    dp[u][0] += base;
    for (int i = 0; i < (int)dif.size(); i += 2) {
      if (i + 1 >= (int)dif.size())
        break;
      sum += dif[i] + dif[i + 1];
      cnt = max(cnt, sum);
    }
    dp[u][0] += cnt;
  };
  dfs(0, 0);
  cout << max(dp[0][0], dp[0][1]) << "\n";
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