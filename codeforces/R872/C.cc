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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<int> hson(n, -1), size(n);
  function<void(int, int)> build = [&](int u, int fa) {
    size[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      build(v, u);
      size[u] += size[v];
      if (hson[u] == -1 || size[v] > size[hson[u]]) {
        hson[u] = v;
      }
    }
  };
  build(0, 0);
  dbg(size, hson);
  vector<set<int>> st(n);
  vector<int> tag(n), dp(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    if (hson[u] == -1) {
      st[u].emplace(0);
      tag[u] = a[u];
      dp[u] = 0;
    } else {
      map<int, int> mp;
      dfs(hson[u], u);
      swap(tag[u], tag[hson[u]]);
      swap(st[u], st[hson[u]]);
      int cnt = 1, sum = dp[hson[u]], w = 1;
      for (auto v : E[u]) {
        if (v == fa || v == hson[u])
          continue;
        dfs(v, u);
        for (auto &x : st[v]) {
          mp[x ^ tag[v]]++;
        }
        cnt++, sum += dp[v];
      }
      for (auto &[x, val] : mp) {
        if (st[u].contains(x ^ tag[u]))
          val++;
        w = max(w, val);
      }
      if (w == 1) {
        for (auto &[x, val] : mp) {
          st[u].emplace(x ^ tag[u]);
        }
      } else {
        st[u].clear();
        for (auto &[x, val] : mp) {
          if (val == w) {
            st[u].emplace(x ^ tag[u]);
          }
        }
      }
      tag[u] ^= a[u];
      dp[u] = sum + cnt - w;
    }
    dbg(u, st[u]);
  };
  dfs(0, 0);
  if (st[0].contains(tag[0])) {
    cout << dp[0] << "\n";
  } else {
    cout << dp[0] + 1 << "\n";
  }
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