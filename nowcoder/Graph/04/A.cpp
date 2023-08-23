#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<int> vis(n), link(n), rlink(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
  }
  function<bool(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        rlink[u] = v;
        return true;
      }
    }
    return false;
  };
  fill(link.begin(), link.end(), -1);
  fill(rlink.begin(), rlink.end(), -1);
  for (int i = 0; i < n; ++i) {
    fill(vis.begin(), vis.end(), 0);
    dfs(i);
  }
  vector<vector<int>> ans;
  vector<int> tmp;
  fill(vis.begin(), vis.end(), 0);
  function<void(int)> cal = [&](int u) {
    tmp.emplace_back(u);
    vis[u] = 1;
    if (rlink[u] != -1) {
      cal(rlink[u]);
    }
  };
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      tmp.clear();
      cal(i);
      ans.emplace_back(tmp);
    }
  }
  for (auto &i : ans) {
    for (auto &j : i) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
  cout << ans.size() << "\n";
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