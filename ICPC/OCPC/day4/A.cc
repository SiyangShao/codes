#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = size_t;
auto solve() {
  st n;
  cin >> n;
  vector<vector<int>> E(n * 2);
  vector<pair<int, int>> eve;
  for (st i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u *= 2, v = v * 2 + 1;
    eve.emplace_back(u, i * 2);
    eve.emplace_back(v, i * 2 + 1);
    E[i * 2].emplace_back(i * 2 + 1), E[i * 2 + 1].emplace_back(i * 2);
  }
  sort(eve.begin(), eve.end());
  for (auto it = eve.begin(); it < eve.end(); it = it + 2) {
    auto nxt = it + 1;
    E[it->second].emplace_back(nxt->second);
    E[nxt->second].emplace_back(it->second);
  }
  vector<int> color(n * 2, -1);
  function<void(st, int)> dfs = [&](st u, int c) {
    color[u] = c;
    for (auto v : E[u]) {
      if (color[v] == -1) {
        dfs(v, c ^ 1);
      }
    }
  };
  for (st i = 0; i < n * 2; ++i) {
    if (color[i] == -1) {
      dfs(i, 0);
    }
  }
  cout << "YES\n";
  for (st i = 0; i < n; ++i) {
    cout << (color[i * 2] ? 1 : -1) << " ";
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