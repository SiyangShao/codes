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
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  string s;
  cin >> s;
  function<void(int, int)> dp = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa) {
        continue;
      }
      dp(v, u);
    }
  };
  vector<int> is_leaf(n);
  for (int i = 0; i < n; ++i) {
    if (E[i].size() == 1) {
      is_leaf[i] = 1;
    }
  }
  int zero = 0, one = 0, other = 0, o2 = 0;
  for (int i = 1; i < n; ++i) {
    if (is_leaf[i]) {
      if (s[i] == '0')
        zero++;
      else if (s[i] == '1')
        one++;
      else
        other++;
    } else if (s[i] == '?') {
      o2++;
    }
  }
  if (s[0] == '0') {
    int ans = one + (other + 1) / 2;
    cout << ans << "\n";
  } else if (s[0] == '1') {
    int ans = zero + (other + 1) / 2;
    cout << ans << "\n";
  } else {
    dbg(zero, one, other, o2);
    int ans = max(zero, one) + other / 2;
    if (o2 % 2 == 1) {
      // can let other decide first
      ans = max(ans, min(zero, one) + (other + 1) / 2);
    }
    cout << ans << "\n";
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