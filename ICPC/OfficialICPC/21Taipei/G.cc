#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 5> dx = {-1, 0, 1, 0, 0}, dy = {0, 1, 0, -1, 0};
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector mp(n, vector<ll>(m));
  for (ll i = 0; i < m; ++i) {
    for (ll j = 0; j < n; ++j) {
      cin >> mp[j][i];
    }
  }
  ll sx, sy;
  cin >> sx >> sy;
  ll g;
  ll bs = 1;
  cin >> g;
  vector<vector<pair<ll, ll>>> G(g);
  for (auto &k : G) {
    ll t;
    cin >> t;
    bs = lcm(bs, t);
    k.resize(t);
    for (auto &[x, y] : k) {
      cin >> x >> y;
    }
  }
  vector dp(bs, vector(n, vector<ll>(m, -1)));
  for (auto &k : G) {
    const auto sz = k.size();
    for (ll i = 0; i < bs; ++i) {
      dp[i][k[i % sz].first][k[i % sz].second] = -2;
      dp[(i + 1) % bs][k[i % sz].first][k[i % sz].second] = -2;
    }
  }
  queue<tuple<ll, ll, ll>> Q;
  dp[0][sx][sy] = 0;
  Q.emplace(0, sx, sy);
  while (!Q.empty()) {
    auto [t, x, y] = Q.front();
    Q.pop();
    if (mp[x][y] == 0) {
      cout << dp[t][x][y] << "\n";
      return;
    }
    for (ll i = 0; i < 5; ++i) {
      ll nxt = t + 1, nx = x + dx[i], ny = y + dy[i];
      nxt %= bs;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || mp[nx][ny] > mp[x][y])
        continue;
      if (dp[nxt][nx][ny] == -1) {
        dp[nxt][nx][ny] = dp[t][x][y] + 1;
        Q.emplace(nxt, nx, ny);
      }
    }
  }
  cout << "-1\n";
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