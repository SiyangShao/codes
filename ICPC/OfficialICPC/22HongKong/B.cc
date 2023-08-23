#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> p(n + 2, vector<ll>(m + 2));
  auto q = p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> p[i][j];
      p[i][j] += p[i][j - 1];
      p[i][j] %= MOD;
      if (j == m)
        assert(p[i][j] == 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> q[i][j];
      q[i][j] += q[i - 1][j];
      q[i][j] %= MOD;
      if (i == n)
        assert(q[i][j] == 1);
    }
  }
  ll ans = 0;
  for (int i = 1; i + 1 <= n; ++i) {
    for (int j = 1; j + 1 <= m; ++j) {
      ll pos = p[i][j - 1] * (1 - q[i - 1][j + 1] + MOD) % MOD;
      pos *= q[i - 1][j] * (1 - p[i + 1][j - 1] + MOD) % MOD;
      pos %= MOD;
      ans += pos;
      ans %= MOD;
    }
    // cout<<"\n";
  }
  ans+=2;
  ans %= MOD;
  cout << ans << "\n";
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