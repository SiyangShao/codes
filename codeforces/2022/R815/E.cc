#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> mp(n, vector<ll>(n));
  vector<array<ll, 4>> all(n * n, {inf, -inf, inf, -inf});
  fill(all.begin(), all.end(), array<ll, 4>{inf, -inf, inf, -inf});
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      cin >> mp[i][j];
      mp[i][j]--;
      all[mp[i][j]][0] = min(all[mp[i][j]][0], i);
      all[mp[i][j]][1] = max(all[mp[i][j]][1], i);
      all[mp[i][j]][2] = min(all[mp[i][j]][2], j);
      all[mp[i][j]][3] = max(all[mp[i][j]][3], j);
    }
  }
  ll cnt = 0;
  for (auto &i : all) {
    if (i[0] != inf) {
      cnt++;
    }
  }
  if (cnt <= k) {
    // Obviously, if cnt <= k, we can choose k - cnt elements and make them
    // different
    cout << k - cnt << "\n";
    return;
  }
  // k < cnt
  // assume: we need *at most* 2 times to make it satisfy the answer
  // The first: 1*1 - p*p, which the rest part contains color's number is larger
  // or equal than k-1. Then we choose another squre which right bottom is p+1,
  // p+1. It's obvious that we can use it to got k different colors.
  // Thus, if there exists an squre, in which it equals to cnt - k or cnt -
  // k + 1, the answer is 1.
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  for (ll len = 1; len <= n; ++len) {
    for (auto &i : dp) {
      fill(i.begin(), i.end(), 0);
    }
    for (auto [mn_x, mx_x, mn_y, mx_y] : all) {
      if (mn_x == inf)
        continue;
      mx_x = max(0LL, mx_x - len + 1);
      mx_y = max(0LL, mx_y - len + 1);
      mn_x = min(mn_x, n - len);
      mn_y = min(mn_y, n - len);
      if (mx_x <= mn_x && mx_y <= mn_y) {
        ++dp[mx_x][mx_y];
        --dp[mx_x][mn_y + 1];
        --dp[mn_x + 1][mx_y];
        ++dp[mn_x + 1][mn_y + 1];
      }
    }
    for (ll x = 0; x < n; ++x) {
      for (ll y = 0; y < n; ++y) {
        if (x == 0 && y == 0)
          continue;
        if (x == 0)
          dp[x][y] += dp[x][y - 1];
        else if (y == 0)
          dp[x][y] += dp[x - 1][y];
        else
          dp[x][y] += dp[x - 1][y] + dp[x][y - 1] - dp[x - 1][y - 1];
      }
    }
    for (ll x = 0; x < n; ++x) {
      for (ll y = 0; y < n; ++y) {
        if (cnt - dp[x][y] == k || cnt - dp[x][y] + 1 == k) {
          cout << "1\n";
          return;
        }
      }
    }
  }
  cout << "2\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin>>_;
  while (_--) {
    solve();
  }
}