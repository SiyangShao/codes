#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll n;
  cin >> n;
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  vector<ll> dp(n * n, inf);
  vector<ll> vis(n * n, 0), is_land(n * n, 0);
  dp[0] = 0, vis[0] = 1;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
  auto cal = [&](ll x, ll y) { return x * n + y; };
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      is_land[cal(i, j)] = (mp[i][j] == '1') ? 1 : 0;
    }
  }
  array dx = {-n, -1LL, 1LL, n};
  Q.emplace(0, 0);
  while (!Q.empty()) {
    auto [dis, cur] = Q.top();
    Q.pop();
    if (!vis[cur])
      continue;
    vis[cur] = 0;
    for (ll i = 0; i < 4; ++i) {
      if (cur % n == 0 && i == 1)
        continue;
      if (cur % n == n - 1 && i == 2)
        continue;
      ll up = cur + dx[i];
      if (up >= 0 && up < n * n) {
        ll nw = dis + (is_land[up] ? 0 : 1);
        if (nw < dp[up]) {
          dp[up] = nw;
          Q.emplace(dp[up], up);
          vis[up] = 1;
        }
      }
    }
  }
  cout << dp[n * n - 1] << "\n";
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