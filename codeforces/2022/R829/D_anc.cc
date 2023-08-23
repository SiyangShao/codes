
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
array dx = {-1, 0, 1, 0};
array dy = {0, -1, 0, 1};
auto solve() {
  ll n, m;
  cin >> n >> m;
  ll p, q;
  cin >> p >> q;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  vector dis(n, vector<ll>(m, inf));
  vector vis(n, vector<ll>(m, 0));
  using pii = pair<ll, ll>;
  using ppii = pair<ll, pii>;
  priority_queue<ppii, vector<ppii>, greater<>> Q;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (mp[i][j] == '.') {
        dis[i][j] = 0;
        Q.emplace(dis[i][j], pii{i, j});
      }
    }
  }
  function<void(ll, ll, ll)> spread = [&](ll x, ll y, ll d) {
    if (x < 0 || y < 0 || x >= n || y >= m)
      return;
    if (vis[x][y])
      return;
    vis[x][y] = 1;
    dis[x][y] = d;
    if (x - 1 >= 0) {
      switch (mp[x - 1][y]) {
      case 'D':
        Q.emplace(d + q, pii{x - 2, y});
        break;
      case 'R':
        Q.emplace(d + p, pii{x - 1, y - 1});
        break;
      case 'L':
        Q.emplace(d + p, pii{x - 1, y + 1});
        break;
      }
    }
    if (x + 1 < n) {
      switch (mp[x + 1][y]) {
      case 'U':
        Q.emplace(d + q, pii{x + 2, y});
        break;
      case 'R':
        Q.emplace(d + p, pii{x + 1, y - 1});
        break;
      case 'L':
        Q.emplace(d + p, pii{x + 1, y + 1});
        break;
      }
    }
    if (y - 1 >= 0) {
      switch (mp[x][y - 1]) {
      case 'R':
        Q.emplace(d + q, pii{x, y - 2});
        break;
      case 'D':
        Q.emplace(d + p, pii{x - 1, y - 1});
        break;
      case 'U':
        Q.emplace(d + p, pii{x + 1, y - 1});
        break;
      }
    }
    if (y + 1 < m) {
      switch (mp[x][y + 1]) {
      case 'L':
        Q.emplace(d + q, pii{x, y + 2});
        break;
      case 'D':
        Q.emplace(d + p, pii{x - 1, y + 1});
        break;
      case 'U':
        Q.emplace(d + p, pii{x + 1, y + 1});
        break;
      }
    }
  };
  while (!Q.empty()) {
    auto [d, pos] = Q.top();
    Q.pop();
    auto [x, y] = pos;
    spread(x, y, d);
  }
  ll ans = inf;
  auto check = [&](ll x, ll y, ll nx, ll ny) {
    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
      return inf;
    if (dis[x][y] >= inf || dis[nx][ny] >= inf) {
      return inf;
    }
    return dis[x][y] + dis[nx][ny];
  };
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      if (!vis[i][j])
        continue;
      for (ll k = 0; k < 4; ++k) {
        ll nx = i + dx[k], ny = j + dy[k];
        ans = min(ans, check(i, j, nx, ny));
      }
    }
  }
  if (ans >= inf) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
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