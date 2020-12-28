#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector dp(n * 2 + 1, vector<vector<ll>>(k + 1, vector<ll>(k + 1, 0)));
  vector<ll> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<>());
  for (auto &i : b) {
    cin >> i;
  }
  sort(b.begin(), b.end(), greater<>());
  for (ll t = 2 * n - 1; t >= 0; --t) {
    if (t % 2 == 0) {
      for (ll x = 0; x <= k; ++x) {
        for (ll y = 0; y <= k; ++y) {
          dp[t][x][y] = -inf;
          if (x + 1 <= k && x + t / 2 - y + 1 <= n && x + t / 2 - y >= 0) {
            dp[t][x][y] =
                max(dp[t][x][y], dp[t + 1][x + 1][y] + a[x + t / 2 - y]);
          }
          if (t / 2 - x + y < n) {
            dp[t][x][y] = max(dp[t][x][y], dp[t + 1][x][y]);
          }
        }
      }
    } else {
      for (ll x = 0; x <= k; ++x) {
        for (ll y = 0; y <= k; ++y) {
          dp[t][x][y] = inf;
          if (y + 1 <= k && y + t / 2 + 1 - x + 1 <= n &&
              y + t / 2 + 1 - x >= 0) {
            dp[t][x][y] =
                min(dp[t][x][y], dp[t + 1][x][y + 1] - b[y + t / 2 + 1 - x]);
          }
          if (t / 2 - y + x < n) {
            dp[t][x][y] = min(dp[t][x][y], dp[t + 1][x][y]);
          }
        }
      }
    }
  }
  cout << dp[0][0][0] << "\n";
}
