#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<array<ll, 4>>> dp(
      2, vector<array<ll, 4>>(n + 1, {-inf, -inf, -inf, -inf}));
  ll cur = 0;
  dp[cur][0][3] = 0;
  for(ll i = 1; i <= n; ++i){
    cur ^= 1;
    for(ll x = 1; x <= n; ++x){
      dp[cur][x][0] = max(dp[cur][x][0], dp[cur^1][x][0]);
      dp[cur][x][0] = max(dp[cur][x][0], dp[cur ^ 1][x - 1][3]);
      // min
      dp[cur][x][1] = max(dp[cur][x][1], dp[cur ^ 1][x][1]);
      dp[cur][x][1] = max(dp[cur][x][1], dp[cur ^ 1][x - 1][3] - a[i - 1]);
      dp[cur][x][1] = max(dp[cur][x][1], dp[cur][x][0] - a[i - 1]);
      // max
      dp[cur][x][2] = max(dp[cur][x][2], dp[cur ^ 1][x][2]);
      dp[cur][x][2] = max(dp[cur][x][2], dp[cur ^ 1][x - 1][3] + a[i - 1]);
      dp[cur][x][2] = max(dp[cur][x][2], dp[cur][x][0] + a[i - 1]);
      // total
      dp[cur][x][3] = max(dp[cur][x][3], dp[cur ^ 1][x][3]);
      dp[cur][x][3] = max(dp[cur][x][3], dp[cur ^ 1][x - 1][3]);
      dp[cur][x][3] = max(dp[cur][x][3], dp[cur ^ 1][x][1] + a[i - 1]);
      dp[cur][x][3] = max(dp[cur][x][3], dp[cur ^ 1][x][2] - a[i - 1]);
    }
  }
  for(ll i = 1; i<= n; ++i){
    cout << dp[cur][i][3] << "\n";
  }
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