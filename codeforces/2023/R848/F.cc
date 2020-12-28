#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1010;
array<vector<int>, N> divs;
constexpr int inf = 1e9;
auto init() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divs[j].emplace_back(i);
    }
  }
}
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<vector<int>> E(n);
  vector<vector<pair<int,int>>> dp(n);
  auto aft_gcd = a;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  if (k == 0) {
    cout << a[0] << "\n";
    return;
  }
  k--;
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
    }
    for (auto i : divs[a[u]]) {
      int cnt = 0;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        int add = inf;
        for (auto [j, val] : dp[v]) {
          if (j % i == 0) {
            add = min(add, val);
          }
          if (j * j % i == 0) {
            add = min(add, val + 1);
          }
        }
        cnt += add;
        if (cnt > k)
          break;
      }
      if (cnt <= k) {
        dp[u].emplace_back(i, cnt);
      }
    }
  };
  dfs(0, 0);
  int ans = a[0];
  for (auto &[j, val] : dp[0]) {
    ans = max(ans, j * a[0]);
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}