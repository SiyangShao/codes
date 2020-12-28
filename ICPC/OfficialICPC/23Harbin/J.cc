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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> vis(n), siz(n, 1);
  array<int, 2> num;
  num[0] = num[1] = 0;
  function<void(int, int)> dfs = [&](int u, int fa) {
    vis[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      siz[u] ^= siz[v];
    }
  };
  vector<int> root;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      root.emplace_back(i);
      dfs(i, i);
      num[siz[i]] ^= 1;
    }
  }
  int ans = 0;
  function<void(int, int)> dpNode = [&](int u, int fa) {
    num[siz[u]] ^= 1;
    for (auto v : E[u]) {
      num[siz[v]] ^= 1;
    }
    if (num[0] == num[1] && num[0] == 0)
      ans++;
    num[siz[u]] ^= 1;
    for (auto v : E[u]) {
      num[siz[v]] ^= 1;
    }
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      siz[u] ^= siz[v];
      siz[v] ^= siz[u];
      dpNode(v, u);
      siz[v] ^= siz[u];
      siz[u] ^= siz[v];
    }
  };
  function<void(int, int)> dpEdg = [&](int u, int fa) {
    num[siz[u]] ^= 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      num[siz[u] ^ siz[v]] ^= 1;
      num[siz[v]] ^= 1;
      if (num[0] == num[1] && num[0] == 0)
        ans++;
      num[siz[u] ^ siz[v]] ^= 1;
      num[siz[v]] ^= 1;
    }
    num[siz[u]] ^= 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      siz[u] ^= siz[v];
      siz[v] ^= siz[u];
      dpEdg(v, u);
      siz[v] ^= siz[u];
      siz[u] ^= siz[v];
    }
  };
  // cout << ans << "\n";
  for (auto u : root) {
    dpNode(u, u);
    dpEdg(u, u);
  }
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