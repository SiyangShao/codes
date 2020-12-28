#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n, s, t;
  cin >> n >> s >> t;
  s--, t--;
  vector<vector<int>> E(n);
  vector<int> deg(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
    deg[u]++, deg[v]++;
  }
  /*
  Suppose f(edg) is the expected number of path edg
  if edg is on the path from s to t, than f(edg) = f(-edg) + 1
  or f(edg) = f(-edg)
  */
  vector<int> fa(n, -1);
  function<void(int)> init = [&](int u) {
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      fa[v] = u;
      init(v);
    }
  };
  init(s);
  vector<ll> f(n), c(n);
  vector<int> in_path(n, 0);
  {
    int u = t;
    while (u != s) {
      in_path[u] = 1;
      f[fa[u]] = f[u] + 1;
      u = fa[u];
    }
    in_path[u] = 1;
  }
  function<void(int)> dfs = [&](int u) {
    if (!in_path[u]) {
      f[u] = f[fa[u]];
    }
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      dfs(v);
    }
  };
  dfs(s);
  for (int i = 0; i < n; ++i) {
    c[i] = f[i] * (ll)E[i].size() % MOD;
  }
  c[t] = 1;
  for (auto i : c) {
    cout << i << " ";
  }
  cout << "\n";
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