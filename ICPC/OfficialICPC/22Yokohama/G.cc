#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> mp(n * 2 + 1);
  for (auto &i : mp)
    cin >> i;
  vector<vector<int>> E(n * m);
  vector<vector<int>> can(n * m);
  vector<int> fa(n * m, -1), dis(n * m, 1), dist(n * m, 1);
  for (int i = 1; i < n * 2 + 1; i += 2) {
    for (int j = 1; j < m * 2 + 1; j += 2) {
      int u = i / 2, v = j / 2;
      if (mp[i][j + 1] == '.') {
        E[u * m + v].emplace_back(u * m + v + 1);
        E[u * m + v + 1].emplace_back(u * m + v);
      }
      if (mp[i + 1][j] == '.') {
        E[u * m + v].emplace_back(u * m + m + v);
        E[u * m + m + v].emplace_back(u * m + v);
      }
      if (v + 1 < m)
        can[u * m + v].emplace_back(u * m + v + 1);
      if (v > 0)
        can[u * m + v].emplace_back(u * m + v - 1);
      if (u > 0)
        can[u * m + v].emplace_back(u * m + v - m);
      if (u + 1 < n)
        can[u * m + v].emplace_back(u * m + v + m);
    }
  }
  function<void(int)> dfs = [&](int u) {
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      fa[v] = u;
      dis[v] = dis[u] + 1;
      dfs(v);
    }
  };
  dfs(0);

  function<void(int, int)> revDfs = [&](int u, int pa) {
    for (auto v : E[u]) {
      if (v == pa)
        continue;
      dist[v] = dist[u] + 1;
      revDfs(v, u);
    }
  };
  revDfs(n * m - 1, n * m - 1);
  // for (int i = 0; i < n * m; ++i) {
  //   cout << dis[i] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i < n * m; ++i) {
  //   cout << dist[i] << " ";
  // }
  // cout << "\n";
  int ans = dis[n * m - 1];
  vector<int> vis(n * m, 0);
  int cur = n * m - 1;
  vector<int> tmp;
  function<void(int)> dp = [&](int u) {
    tmp.emplace_back(u);
    vis[u] = 1;
    for (auto v : E[u]) {
      if (v == fa[u])
        continue;
      if (vis[v])
        continue;
      dp(v);
    }
  };
  while (cur != 0) {
    // cut cur-facur
    tmp.clear();
    dp(cur);
    for (auto u : tmp) {
      for (auto v : can[u]) {
        if (!vis[v]) {
          ans = max(ans, dis[v] + dist[u]);
        }
      }
    }
    cur = fa[cur];
  }
  cout << ans << "\n";
}