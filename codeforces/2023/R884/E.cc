#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> E(n + m);
  for (int i = 0; i < k; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    if (y2 == y1 + 1) {
      E[x2].emplace_back(n + y2, 1);
      E[n + y2].emplace_back(x2, 1);
    } else {
      E[x2].emplace_back(n + y1, 0);
      E[n + y1].emplace_back(x2, 0);
    }
  }
  vector<int> col(n + m, -1);
  function<bool(int)> dfs = [&](int u) {
    for (auto [v, d] : E[u]) {
      if (col[v] == -1) {
        col[v] = col[u] ^ d;
        if (!dfs(v)) {
          return false;
        }
      } else {
        if (col[v] != (col[u] ^ d)) {
          return false;
        }
      }
    }
    return true;
  };
  for (int i = 0; i < n + m; ++i) {
    if (col[i] == -1) {
      col[i] = 0;
      if (!dfs(i)) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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
