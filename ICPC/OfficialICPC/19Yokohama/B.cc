#include <bits/stdc++.h>
using namespace std;
array dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, d;
  cin >> n >> m >> d;
  vector mp(n, vector<int>(m, -200));
  vector<tuple<int, int, int>> should;
  while (d--) {
    vector cur(n, vector<int>(m, 200));
    vector vis(n, vector<bool>(m, false));
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    should.emplace_back(a, b, c);
    queue<tuple<int, int, int>> Q;
    Q.emplace(a, b, c);
    while (!Q.empty()) {
      auto [u, v, i] = Q.front();
      Q.pop();
      if (vis[u][v])
        continue;
      vis[u][v] = true;
      cur[u][v] = i;
      for (int j = 0; j < 4; ++j) {
        int x = u + dx[j], y = v + dy[j];
        if (x < 0 || x >= n || y < 0 || y >= m)
          continue;
        if (vis[x][y])
          continue;
        Q.emplace(x, y, i - 1);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mp[i][j] = max(mp[i][j], cur[i][j]);
      }
    }
  }
  for (auto [a, b, c] : should) {
    mp[a][b] = c;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += mp[i][j];
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m)
          continue;
        if (abs(mp[x][y] - mp[i][j]) > 1) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  cout << ans << "\n";
}