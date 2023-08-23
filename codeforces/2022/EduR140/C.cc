#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto solve() {
  int n;
  cin >> n;
  vector a(n, vector<ll>(n));
  auto dp = a;
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
      cin >> a[i][j];
  if (a[0][0] != 2)
    dp[1][0] = 2;
  auto check = [&](int cnt, int lst) {
    for (int i = 0; i < cnt; ++i) {
      if (a[i][cnt - 1] == 0)
        continue;
      if (a[i][cnt - 1] == 1 && lst > i)
        return false;
      if (a[i][cnt - 1] == 2 && lst <= i)
        return false;
    }
    return true;
  };
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < i; ++j)
      for (auto k : {j, i})
        if (check(i + 1, k))
          dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans = (ans + dp[n][i]) % MOD;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}
