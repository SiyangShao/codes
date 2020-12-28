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
  if (n == 1) {
    cout << "2\n";
    return;
  } else if (n == 2) {
    cout << "1\n";
    return;
  }
  vector<vector<int>> E(n);
  vector<int> deg(n), f(n);
  for ([[maybe_unused]] auto _ : ranges::views::iota(1, n)) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
    deg[u]++, deg[v]++;
  }
  vector<int> dep(n);
  int rt = -1;
  for (auto u : ranges::views::iota(0, n)) {
    if (deg[u] != 1) {
      rt = u;
      break;
    }
  }
  assert(rt != -1);
  function<void(int, int)> dfs = [&](int u, int fa) {
    f[u] = fa;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  };
  dfs(rt, rt);
  f[rt] = -1;
  priority_queue<pair<int, int>> Q;
  for (auto u : ranges::views::iota(0, n)) {
    if (deg[u] == 1) {
      Q.emplace(dep[u], u);
    }
  }
  int ans = 0;
  vector<int> del(n);
  while (!Q.empty()) {
    auto [_, u] = Q.top();
    // cout << u + 1 << ", " << ans << "\n";
    Q.pop();
    if (del[u])
      continue;
    del[u] = 1;
    if (f[u] == -1 || del[f[u]] || deg[f[u]] > 2) {
      ans += 2;
      if (f[u] != -1 && !del[f[u]]) {
        deg[f[u]]--;
      }
    } else {
      ans++;
      del[f[u]] = 1;
      for (auto v : E[f[u]]) {
        deg[v]--;
      }
      if (f[f[u]] != -1) {
        Q.emplace(dep[f[f[u]]], f[f[u]]);
      }
    }
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