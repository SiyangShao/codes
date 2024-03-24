#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
array dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
constexpr ll inf = 1e16;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }
  vector<string> mp(n);
  for (auto &i : mp)
    cin >> i;
  vector del(n, vector<ll>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '#')
        del[i][j] = inf;
    }
  }
  for (int i = 0; i < k; ++i) {
    del[x[i]][y[i]] = k - i;
  }
  vector dis(n, vector<ll>(m, inf));
  vector vis(n, vector<int>(m, 0));
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> Q;
  Q.emplace(0, x[0], y[0]);
  dis[x[0]][y[0]] = 0;
  while (!Q.empty()) {
    auto [_, ux, uy] = Q.top();
    Q.pop();
    if (vis[ux][uy])
      continue;
    vis[ux][uy] = 1;
    for (int i = 0; i < 4; ++i) {
      int vx = ux + dx[i], vy = uy + dy[i];
      if (vx < 0 || vy < 0 || vx >= n || vy >= m)
        continue;
      if (dis[vx][vy] > max(del[vx][vy], dis[ux][uy] + 1)) {
        dis[vx][vy] = max(del[vx][vy], dis[ux][uy] + 1);
        Q.emplace(dis[vx][vy], vx, vy);
      }
    }
  }
  ull ans = 0;
  for (auto &i : dis) {
    for (auto &j : i) {
      if (j >= inf)
        continue;
      ans += (ull)j * (ull)j;
    }
  }
  cout << ans << "\n";
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