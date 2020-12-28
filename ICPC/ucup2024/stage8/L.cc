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
  vector<int> in(n), out(n), vis(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    in[v]++;
    out[u]++;
  }
  auto E2 = E;
  vector<vector<int>> line;
  vector<int> cur;
  function<void(int)> dfs = [&](int u) {
    cur.emplace_back(u);
    if (E2[u].empty())
      return;
    auto v = E2[u].back();
    E2[u].pop_back();
    out[u]--;
    in[v]--;
    dfs(v);
  };
  while (true) {
    cur.clear();
    for (int j = 0; j < n; ++j) {
      if (in[j] < out[j]) {
        dfs(j);
        break;
      }
    }
    if (cur.empty())
      break;
    line.emplace_back(cur);
  }
  vector<int> ans(n, 1);
  fill(vis.begin(), vis.end(), 0);
  int cnt = 0;
  dfs = [&](int u) {
    vis[u] = 1;
    cnt++;
    for (auto v : E[u]) {
      if (!vis[v]) {
        dfs(v);
      }
    }
  };
  dbg(line);
  for (auto &vec : line) {
    reverse(vec.begin(), vec.end());
    fill(vis.begin(), vis.end(), 0);
    cnt = 0;
    for (auto i : vec) {
      dfs(i);
      ans[i] = cnt;
    }
  }
  for (auto i : ans) {
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