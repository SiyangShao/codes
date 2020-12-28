#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
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
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  if (n == 2) {
    cout << "1\n";
    return;
  }
  int root = -1;
  for (int i = 0; i < n; ++i) {
    if ((int)E[i].size() > 1) {
      root = i;
      break;
    }
  }
  vector<int> odd(n), even(n);
  int ans = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    if ((int)E[u].size() == 1) {
      odd[u] = 1;
      return;
    }

    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      assert(odd[v] == 0 || even[v] == 0);
      odd[u] += odd[v];
      even[u] += even[v];
    }
    // cout << u + 1 << " " << odd[u] << " " << even[u] << "\n";
    while (even[u] >= 2) {
      even[u] -= 2;
      ans++;
    }
    while (odd[u] >= 3) {
      odd[u] -= 2;
      ans++;
    }
    if (even[u] == 0) {
      if (odd[u] == 0) {
        return;
      } else if (odd[u] == 1) {
        return;
      } else {
        assert(odd[u] == 2);
        odd[u] = 0;
        even[u] = 1;
      }
    } else {
      if (odd[u] == 0) {
        odd[u] = 0;
        even[u] = 1;
      } else if (odd[u] == 1) {
        even[u] = 1;
        odd[u] = 0;
      } else {
        assert(odd[u] == 2);
        ans++;
        odd[u] = 1;
        even[u] = 0;
      }
    }
  };
  dfs(root, -1);
  if (even[root] != 0)
    ans++;
  cout << ans << "\n";
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