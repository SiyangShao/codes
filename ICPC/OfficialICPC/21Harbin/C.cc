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
    int fa;
    cin >> fa;
    fa--;
    E[fa].emplace_back(i);
  }
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
  }
  vector<int> dp(n), mx(n);
  vector<map<int, int>> mp(n);
  // vector<set<int>> st(n);
  function<void(int)> dfs = [&](int u) {
    int max_size = 0, max_son = -1;
    for (auto v : E[u]) {
      dfs(v);
      if ((int)mp[v].size() > max_size) {
        max_size = (int)mp[v].size();
        max_son = v;
      }
    }
    if (max_son == -1) {
      // is leaf
      mp[u][c[u]]++;
      // st[u].emplace(c[u]);
      mx[u] = 1;
      dp[u] = 1;
      return;
    }
    // swap(st[u], st[max_son]);
    swap(mp[u], mp[max_son]);
    swap(mx[u], mx[max_son]);
    swap(dp[u], dp[max_son]);
    map<int, int> tmpmp;
    function<void(int)> add = [&](int col) {
      mp[u][col]++;
      mx[u] = max(mx[u], mp[u][col]);
      // if (mp[u][col] > mx[u]) {
      //   mx[u] = mp[u][col];
      //   st[u].clear();
      //   st[u].emplace(col);
      // } else if (mp[u][col] == mx[u]) {
      //   st[u].emplace(col);
      // }
    };
    for (auto v : E[u]) {
      if (v == max_son)
        continue;
      for (auto [i, _] : mp[v]) {
        add(i);
      }
      mp[v].clear();
      dp[u] += dp[v];
    }
    dp[u] -= mx[u];
    dp[u]++;
    if (mx[u] != 1) {
      tmpmp.clear();
      for (auto [i, cnt] : mp[u]) {
        if (cnt == mx[u]) {
          tmpmp[i] = 1;
        }
      }
      swap(mp[u], tmpmp);
    }
    mx[u] = 1;
  };
  dfs(0);
  cout << dp[0] << "\n";
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