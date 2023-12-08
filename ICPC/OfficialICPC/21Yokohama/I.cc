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
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<bool> vis(n), del(n);
  vector<int> fa(n, -1), dep(n);
  vector<vector<int>> ans;
  vector<set<int>> child(n);
  function<void(int)> partition = [&](int u) {
    del[u] = true;
    ans.back().emplace_back(u);
    for (auto v : child[u]) {
      if (!del[v])
        partition(v);
    }
  };
  function<int(int)> divide = [&](int u) {
    int siz = 1;
    for (auto v : child[u]) {
      siz += divide(v);
    }
    if (siz % 2 == 0) {
      ans.emplace_back();
      partition(u);
      return 0;
    } else {
      return siz;
    }
  };
  function<int(int)> dfs = [&](int u) {
    vis[u] = true;
    int siz = 1;
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      dep[v] = dep[u] + 1;
      siz += dfs(v);
      if (!del[v]) {
        fa[v] = u;
        child[u].emplace(v);
      }
    }
    for (auto v : E[u]) {
      if (!del[v] && dep[v] > dep[u] && fa[v] != u) {
        int x = fa[v];
        child[x].erase(v);
        fa[v] = u;
        child[u].emplace(v);
        while (fa[x] != u) {
          x = fa[x];
        }
        divide(x);
        child[u].erase(x);
      }
    }
    if (siz % 2 == 0) {
      divide(u);
    }
    return siz;
  };
  dfs(0);
  cout << ans.size() << "\n";
  for (auto &v : ans) {
    cout << v.size();
    for (auto i : v) {
      cout << " " << i;
    }
    cout << "\n";
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