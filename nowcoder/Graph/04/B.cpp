#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e4;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(N), empt(N);
  vector<int> vis(N), link(N), rlink(N);
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
  function<bool(int)> is_square = [&](int u) {
    return (int)sqrt(u) * (int)sqrt(u) == u;
  };
  int col = 0, cur = 0;
  while (col <= n) {
    cur++;
    // cout<<cur<<" "<< col<<"\n";
    for (int i = 1; i < cur; ++i) {
      if (is_square(i + cur)) {
        E[cur].emplace_back(i);
        // E[i].emplace_back(cur);
      }
    }
    fill(vis.begin(), vis.end(), 0);
    if (dfs(cur)) {
      continue;
    } else {
      col++;
    }
  }
  cout << cur - 1 << "\n";
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
  for (int i = cur - 1; i >= 1; --i) {
    if (!vis[i]) {
      tmp.clear();
      cal(i);
      ans.emplace_back(tmp);
    }
  }
  for (auto &i : ans) {
    reverse(i.begin(), i.end());
    for (auto &j : i) {
      cout << j << " ";
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