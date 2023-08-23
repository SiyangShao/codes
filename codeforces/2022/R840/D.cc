#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
auto solve() {
  ll n, p, q, x, y;
  cin >> n >> p >> q >> x >> y;
  p--, q--;
  vector<vector<ll>> dp(n, vector<ll>(n, -1));
  auto check = [&](ll i, ll v) {
    return i >= 0 && i < n && (i != p || x == v) && (i != q || y == v);
  };
  dp[0][n - 1] = 1;
  function<ll(ll, ll, ll)> dfs = [&](ll l, ll r, ll c) {
    if (~dp[l][r])
      return dp[l][r];
    ll res = 0;
    if (check(l - 1, c - 1))
      res += dfs(l - 1, r, c - 1);
    if (check(r + 1, c - 1))
      res += dfs(l, r + 1, c - 1);
    res %= MOD;
    return dp[l][r] = res;
  };
  ll ans = 0;
  for (ll i = 1; i < n - 1; ++i) {
    if (check(i, n))
      ans += dfs(i, i, n);
    ans %= MOD;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}