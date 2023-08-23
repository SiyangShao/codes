#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array dx = {-1LL, 1LL, 0LL, 0LL}, dy = {0LL, 0LL, 1LL, -1LL};
array ndx = {-1LL, -1LL, 1LL, 1LL}, ndy = {-1LL, 1LL, -1LL, 1LL};
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<string> smp(n);
  for (auto &i : smp) {
    cin >> i;
  }
  constexpr ll inf = 1e16;
  vector dis(n, vector<ll>(m, 0));
  vector pre(n, vector<pair<ll, ll>>(m, {-1, -1}));
  auto vis = dis;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      dis[i][j] = inf;
    }
  }
  function<bool(ll, ll)> check = [&](ll x, ll y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
      return false;
    for (ll i = 0; i < 4; ++i) {
      ll nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (smp[nx][ny] == '#')
        return false;
    }
    return true;
  };
  using pii = tuple<ll, ll, ll, ll, ll>;
  priority_queue<pii, vector<pii>, greater<>> Q;
  for (ll i = 0; i < n; ++i) {
    if (check(i, 0)) {
      dis[i][0] = (smp[i][0] == '#' ? 0 : 1);
      Q.emplace(dis[i][0], i, 0, -1, -1);
      // cout<<i<<" ";
    }
  }
  // cout<<"\n";
  ll ans_x = -1, ans_y = -1, pri = n * m;
  while (!Q.empty()) {
    auto [_, x, y, pre_x, pre_y] = Q.top();
    Q.pop();
    if (vis[x][y])
      continue;
    vis[x][y] = 1;
    pre[x][y] = {pre_x, pre_y};
    if (y == m - 1 && _ < pri) {
      ans_x = x;
      ans_y = y;
      pri = _;
    }
    for (ll i = 0; i < 4; ++i) {
      ll nx = x + ndx[i], ny = y + ndy[i];
      if (check(nx, ny)) {
        ll w = 1;
        if (smp[nx][ny] == '#') {
          w = 0;
        }
        if (dis[nx][ny] > dis[x][y] + w) {
          dis[nx][ny] = dis[x][y] + w;
          Q.emplace(dis[nx][ny], nx, ny, x, y);
        }
      }
    }
  }
  if (ans_x == -1 || ans_y == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  while (ans_x != -1 && ans_y != -1) {
    smp[ans_x][ans_y] = '#';
    auto [x, y] = pre[ans_x][ans_y];
    ans_x = x, ans_y = y;
  }
  for (auto &i : smp) {
    cout << i << "\n";
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