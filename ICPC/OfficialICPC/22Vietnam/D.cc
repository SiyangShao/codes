#include <bits/stdc++.h>
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
  vector<int> col(n, -1);
  bool flag = true;
  ll black = 0, white = 0;
  function<void(int)> dfs = [&](int u) {
    if (col[u] == 0) {
      black++;
    } else {
      white++;
    }
    for (auto v : E[u]) {
      if (col[v] == -1) {
        col[v] = col[u] ^ 1;
        dfs(v);
      } else if (col[v] == col[u]) {
        flag = false;
      }
    }
  };
  ll ans = n;
  for (int i = 0; i < n; ++i) {
    flag = true;
    black = white = 0;
    if (col[i] == -1) {
      col[i] = 0;
      dfs(i);
      if (flag) {
        // 二分图
        ans += black * (black - 1) + white * (white - 1);
      } else {
        ans += (black + white) * (black + white - 1);
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}