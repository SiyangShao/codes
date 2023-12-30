#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
  int k;
  cin >> k;
  vector<int> a(k), select(n);
  for (auto &i : a) {
    cin >> i;
    i--;
    select[i] = 1;
  }
  int L = 0, R = n;
  int ans = L;
  auto check = [&](int x) {
    vector<ll> dp(n, 0), mov(n, 0);
    for (int i = 0; i < k; ++i) {
      mov[a[i]] = (x / k + (i < (x % k) ? 1 : 0));
    }
    bool flag = true;
    function<void(int, int)> dfs = [&](int u, int fa) {
      ll nd = mov[u];
      bool can = select[u] ? false : true;
      ll sum = 0;
      for (auto v : E[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        if (dp[v] > 0) {
          if (!can) {
            flag = false;
          }
          can = false;
          nd = dp[v] - 1;
        } else {
          sum = min(sum, dp[v]);
        }
      }
      if (!can) {
        if (nd + sum <= 0) {
          dp[u] = 0;
        } else {
          dp[u] = nd;
        }
      } else {
        dp[u] = sum - 1;
      }
    };
    dfs(0, 0);
    return flag && (dp[0] <= 0);
  };
  // for(int i = L;i<=R;++i){
  //   cout<<check(i)<<" ";
  // }
  // cout << "\n";
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid)) {
      L = mid + 1;
      ans = max(ans, mid);
    } else {
      R = mid - 1;
    }
  }
  cout << ans << "\n";
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