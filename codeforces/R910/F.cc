#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
array dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
struct S {
  int d0 = -1, d1 = -1, f0 = -1, f1 = -1;
  bool update(int i, int v) {
    if (i == -1) {
      return false;
    }
    if (d0 == -1) {
      d0 = v, f0 = i;
      return true;
    }
    if (i == f0) {
      if (v < d0) {
        d0 = v;
        return true;
      }
      return false;
    }
    if (v < d0) {
      d1 = d0, f1 = f0;
      d0 = v, f0 = i;
      return true;
    }
    if (d1 == -1 || v < d1) {
      d1 = v, f1 = i;
      return true;
    }
    return false;
  }
};
auto case2(auto &outsider, auto &mp, auto &dis) {
  int n = static_cast<int>(mp.size()), m = static_cast<int>(mp[0].size());
  vector f(n, vector<S>(m));
  int id = 0;
  queue<pair<int, int>> Q;
  for (auto [u, v] : outsider) {
    f[u][v].update(id++, 0);
    Q.emplace(u, v);
  }
  while (!Q.empty()) {
    auto [u, v] = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      int x = u + dx[i], y = v + dy[i];
      if (x < 0 || x >= n || y < 0 || y >= m)
        continue;
      if (mp[x][y] == '#')
        continue;
      bool up = f[x][y].update(f[u][v].f0, f[u][v].d0 + 1);
      up |= f[x][y].update(f[u][v].f1, f[u][v].d1 + 1);
      if (up)
        Q.emplace(x, y);
    }
  }
  int ans = 1e9;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j].d0 == -1 || f[i][j].d1 == -1)
        continue;
      ans = min(ans, dis[i][j] + f[i][j].d0 + f[i][j].d1);
    }
  }
  return ans;
}
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp)
    cin >> i;
  vector vis(n, vector<int>(m, 0));
  vector dis(n, vector<int>(m, 1e9));
  pair<int, int> start;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      [[unlikely]] if (mp[i][j] == 'V') {
        start = {i, j};
        dis[i][j] = 0;
      } else if (mp[i][j] == '#') {
        vis[i][j] = -1;
      }
    }
  }
  queue<pair<int, int>> Q;
  set<pair<int, int>> outsider;
  Q.emplace(start);
  while (!Q.empty()) {
    auto [u, v] = Q.front();
    Q.pop();
    if (vis[u][v])
      continue;
    vis[u][v] = 1;
    for (int i = 0; i < 4; ++i) {
      int x = u + dx[i], y = v + dy[i];
      if (x < 0 || x >= n || y < 0 || y >= m) {
        outsider.emplace(u, v);
        continue;
      }
      if (vis[x][y])
        continue;
      dis[x][y] = min(dis[x][y], dis[u][v] + 1);
      Q.emplace(x, y);
    }
  }
  int cnt = 0;
  for (auto &i : mp) {
    for (auto &j : i) {
      if (j == '.')
        cnt++;
    }
  }
  if (outsider.empty()) {
    cout << cnt << "\n";
    return;
  } else if (outsider.size() == 1) {
    auto [u, v] = *outsider.begin();
    cout << cnt - dis[u][v] << "\n";
  } else {
    cout << cnt - case2(outsider, mp, dis) << "\n";
  }
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