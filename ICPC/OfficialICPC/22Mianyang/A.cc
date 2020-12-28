#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector dp(n * 2, vector<vector<ll>>(k + 1, vector<ll>(k + 1, -inf)));
  vector<ll> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<>());
  for (auto &i : b) {
    cin >> i;
  }
  sort(b.begin(), b.end(), greater<>());
  function<ll(ll, ll, ll)> dfs = [&](ll t, ll x, ll y) {
    if (t == 2 * n)
      return 0LL;
    if (dp[t][x][y] != -inf) {
      return dp[t][x][y];
    }
    ll ans;
    if ((t & 1) == 0) {
      ans = -inf;
      if (x + 1 <= k && x + t / 2 - y + 1 <= n) {
        ans = max(ans, dfs(t + 1, x + 1, y) + a[x + t / 2 - y]);
      }
      if (t / 2 - x + y < n) {
        ans = max(ans, dfs(t + 1, x, y));
      }
    } else {
      ans = inf;
      if (y + 1 <= k && y + t / 2 + 1 - x + 1 <= n) {
        ans = min(ans, dfs(t + 1, x, y + 1) - b[y + t / 2 + 1 - x]);
      }
      if (t / 2 - y + x < n) {
        ans = min(ans, dfs(t + 1, x, y));
      }
    }
    return dp[t][x][y] = ans;
  };
  dfs(0, 0, 0);
  cout << dp[0][0][0] << "\n";
}
