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
  string s;
  cin >> s;
  ll ans = 0;
  vector<vector<int>> E(n + 1);
  for (int i = 0; i < n; ++i) {
    int j;
    if (s[i] == '1')
      j = i + 3;
    else
      j = i + 1;
    j = min(j, n);
    E[j].emplace_back(i);
  }
  vector<int> sz(n + 1, 1);
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      dfs(v);
      sz[u] += sz[v];
    }
  };
  dfs(n);
  dbg(sz);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      int l = sz[i], r = n - i;
      ans += 1LL * l * r;
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