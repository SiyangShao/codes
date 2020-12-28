#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 100;
struct Matrix {
  array<array<ll, N>, N> a;
  int sz;
  Matrix(int n) : sz(n) {
    for (int i = 0; i < N; ++i) {
      fill(a[i].begin(), a[i].end(), 0);
    }
  }

  Matrix operator*(const Matrix &b) const {
    Matrix res(sz);
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k)
          res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
    return res;
  }
};
void qpow(Matrix &ans, Matrix &base, ll x) {
  while (x) {
    if (x & 1)
      ans = ans * base;
    base = base * base;
    x >>= 1;
  }
}
auto solve() {
  ll n;
  int m;
  cin >> n >> m;
  // trivial dp:
  // dp[i] = dp[i-1] + dp[i - m];
  vector<ll> dp(m, 1);
  if (n < m) {
    cout << dp[n] << "\n";
    return;
  }
  Matrix ans(m);
  for (int i = 0; i < m; ++i) {
    ans.a[0][i] = 1;
  }
  Matrix base(m);
  base.a[0][0] = base.a[0][m - 1] = 1;
  for (int i = 1; i < m; ++i) {
    base.a[i][i - 1] = 1;
  }

  if (n < m) {
    cout << ans.a[0][n] << "\n";
    return;
  }
  qpow(ans, base, n - m + 1);
  cout << ans.a[0][0] % MOD << "\n";
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