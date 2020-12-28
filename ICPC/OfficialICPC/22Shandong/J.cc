#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
#define int ll
auto Eula(vector<pair<int, int>> &edg, int n) {
  int m = (int)edg.size();
  vector<vector<int>> E(n);
  vector<int> in(n), out(n);
  vector<int> cur(n);
  vector<int> vis(m);
  {
    int _id = 1;
    for (auto [u, v] : edg) {
      in[v]++, out[u]++;
      E[u].emplace_back(_id);
      E[v].emplace_back(-_id);
      _id++;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (E[i].size() % 2 != 0) {
      assert(i == 0 || i + 1 == n);
    }
  }
  function<void(int)> dfs = [&](int x) {
    while (cur[x] < (int)E[x].size()) {
      auto id = E[x][cur[x]];
      cur[x]++;
      if (vis[abs(id) - 1]) {
        continue;
      }
      vis[abs(id) - 1] = true;
      auto [u, v] = edg[abs(id) - 1];
      int y = u ^ v ^ x;
      dfs(y);
    }
    ans.emplace_back(x);
  };
  dfs(0);
  // assert((int)ans.size() == (int)m + 1);
  return ans;
}
auto solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> node(n * (n + 1) / 2);
  ll ssum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      // cout << i * (i + 1) / 2 + j << " ";
      node[i * (i + 1) / 2 + j] = {i, j};
    }
    // cout << endl;
  }
  auto change = [&](int i, int j) { return i * (i + 1) / 2 + j; };
  vector<vector<pair<int, int>>> E(n * (n + 1) / 2);
  vector<int> deg(n * (n + 1) / 2);
  for (int i = 0; i + 1 < n; ++i) {
    int a;
    for (int j = 0; j <= i; ++j) {
      // [i,j] to [i+1,j]
      cin >> a;
      ssum += a;
      E[change(i, j)].emplace_back(change(i + 1, j), a);
      E[change(i + 1, j)].emplace_back(change(i, j), a);
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    int a;
    for (int j = 0; j <= i; ++j) {
      // [i,j] to [i+1,j+1]
      cin >> a;
      ssum += a;
      // cout << change(i, j) << " " << change(i + 1, j + 1) << endl;
      E[change(i, j)].emplace_back(change(i + 1, j + 1), a);
      E[change(i + 1, j + 1)].emplace_back(change(i, j), a);
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    int a;
    for (int j = 0; j <= i; ++j) {
      // [i+1,j] to [i+1,j+1]
      cin >> a;
      ssum += a;
      E[change(i + 1, j)].emplace_back(change(i + 1, j + 1), a);
      E[change(i + 1, j + 1)].emplace_back(change(i + 1, j), a);
    }
  }
  for (int i = 0; i < n * (n + 1) / 2; ++i) {
    deg[i] = (int)E[i].size();
    assert(deg[i] % 2 == 0);
  }
  // Shortest Distance from [0,0] to [i,j]
  vector<int> dis(n * (n + 1) / 2, 1e16), vis(n * (n + 1) / 2),
      prev(n * (n + 1) / 2, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
  dis[0] = 0;
  Q.emplace(0, 0);
  while (!Q.empty()) {
    auto [d, u] = Q.top();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, w] : E[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        prev[v] = u;
        Q.emplace(dis[v], v);
      }
    }
  }
  ssum -= dis[n * (n + 1) / 2 - 1];
  fill(vis.begin(), vis.end(), 0);
  {
    int u = n * (n + 1) / 2 - 1;
    while (u != -1) {
      vis[u] = 1;
      if (prev[u] != -1) {
        deg[u]--, deg[prev[u]]--;
      }
      u = prev[u];
    }
  }
  for (int i = 0; i < n * (n + 1) / 2; ++i) {
    if (deg[i] % 2 == 1) {
      assert(i == n * (n + 1) / 2 - 1 || i == 0);
    }
  }
  vector<pair<int, int>> edg;
  for (int i = 0; i < n * (n + 1) / 2; ++i) {
    for (auto [v, w] : E[i]) {
      if (i < v)
        continue;
      if (vis[i] && vis[v] && (i == prev[v] || v == prev[i])) {
        continue;
      }
      edg.emplace_back(i, v);
    }
  }
  auto ans = Eula(edg, n * (n + 1) / 2);
  cout << ssum << endl;
  cout << ans.size() << endl;
  // assert(ans[0] == n * (n + 1) / 2 - 1);
  for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
    auto [x, y] = node[*i];
    if (i == ans.rbegin()) {
      // assert(x == 0 && y == 0);
      cout << x + 1 << " " << y + 1;
    } else {
      cout << " " << x + 1 << " " << y + 1;
    }
  }
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
    if (_)
      cout << endl;
  }
}