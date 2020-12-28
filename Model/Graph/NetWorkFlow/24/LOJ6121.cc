#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, p;
  cin >> n >> m >> p;
  int k;
  cin >> k;
  vector wall(n, vector<vector<vector<int>>>(
                     m, vector<vector<int>>(n, vector<int>(m, -1))));
  for (int i = 0; i < k; ++i) {
    int x1, y1, x2, y2, g;
    cin >> x1 >> y1 >> x2 >> y2 >> g;
    x1--, x2--, y1--, y2--;
    wall[x1][y1][x2][y2] = g;
    wall[x2][y2][x1][y1] = g;
  }
  function<bool(int, int)> valid = [&](int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
      return false;
    return true;
  };
  vector mp(n, vector<vector<int>>(m));
  int s;
  cin >> s;
  vector vis(n, vector<vector<int>>(m, vector<int>(1 << p, 0)));
  for (int i = 0; i < s; ++i) {
    int x, y, q;
    cin >> x >> y >> q;
    x--, y--;
    mp[x][y].emplace_back(q);
  }
  function<bool(int, int, int, int, int)> path = [&](int x, int y, int nx,
                                                     int ny, int msk) {
    if (!valid(nx, ny) || !valid(x, y))
      return false;
    if (wall[x][y][nx][ny] == -1)
      return true;
    if (wall[x][y][nx][ny] == 0)
      return false;
    auto t = wall[x][y][nx][ny] - 1;
    if ((msk >> t) & 1)
      return true;
    return false;
  };
  queue<tuple<int, int, int, int>> Q;
  Q.emplace(0, 0, 0, 0);
  vector dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
  while (!Q.empty()) {
    auto [x, y, d, msk] = Q.front();
    Q.pop();
    if (vis[x][y][msk])
      continue;
    if (x == n - 1 && y == m - 1) {
      cout << d << "\n";
      return 0;
    }
    vis[x][y][msk] = 1;
    for (auto i : mp[x][y]) {
      msk = msk | (1 << (i - 1));
    }
    for (int i = 0; i < 4; ++i) {
      auto nx = x + dx[i], ny = y + dy[i];
      if (path(x, y, nx, ny, msk)) {
        Q.emplace(nx, ny, d + 1, msk);
      }
    }
  }
  cout << "-1\n";
}