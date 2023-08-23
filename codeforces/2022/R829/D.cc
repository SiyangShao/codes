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
  auto shift = [&](ll x, ll y, ll nx, ll ny) {
    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
      return;
    ll d = dis[x][y] + q;
    if (mp[nx][ny] == 'D' && nx == x - 1 && ny == y) {
      Q.emplace(d, pii{nx - 1, ny});
    } else if (mp[nx][ny] == 'U' && nx == x + 1 && ny == y) {
      Q.emplace(d, pii{nx + 1, ny});
    } else if (mp[nx][ny] == 'R' && nx == x && ny == y - 1) {
      Q.emplace(d, pii{nx, ny - 1});
    } else if (mp[nx][ny] == 'L' && nx == x && ny == y + 1) {
      Q.emplace(d, pii{nx, ny + 1});
    }
  };
  auto rotate = [&](ll x, ll y, ll nx, ll ny) {
    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
      return;
    ll d = dis[x][y] + p;
    if (mp[nx][ny] == 'R' && ny == y) {
      Q.emplace(d, pii{nx, ny - 1});
    } else if (mp[nx][ny] == 'L' && ny == y) {
      Q.emplace(d, pii{nx, ny + 1});
    } else if (mp[nx][ny] == 'D' && nx == x) {
      Q.emplace(d, pii{nx - 1, ny});
    } else if (mp[nx][ny] == 'U' && nx == x) {
      Q.emplace(d, pii{nx + 1, ny});
    }
  };
  function<void(ll, ll, ll)> spread = [&](ll x, ll y, ll d) {
    if (x < 0 || y < 0 || x >= n || y >= m)
      return;
    if (vis[x][y])
      return;
    vis[x][y] = 1;
    dis[x][y] = d;
    for (int i = 0; i < 4; ++i) {
      ll nx = x + dx[i], ny = y + dy[i];
      shift(x, y, nx, ny);
      rotate(x, y, nx, ny);
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