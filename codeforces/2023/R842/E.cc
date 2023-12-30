#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qpow(ll x, ll y, const ll M) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % M;
    }
    x = x * x % M;
    y >>= 1;
  }
  return res;
}
ll rev(ll x, const ll M) { return qpow(x, M - 2, M); }
auto solve() {
  ll n, m;
  cin >> n >> m;
  const ll M = m;
  vector<ll> frac(3 * n + 1), inv_frac(3 * n + 1);
  frac[0] = 1;
  for (ll i = 1; i <= 3 * n; ++i) {
    frac[i] = frac[i - 1] * i % M;
  }
  inv_frac[3 * n] = rev(frac[3 * n], M);
  for (ll i = n * 3 - 1; i >= 0; --i) {
    inv_frac[i] = inv_frac[i + 1] * (i + 1) % M;
  }
  auto C = [&](ll x, ll y) {
    return frac[x] * inv_frac[y] % M * inv_frac[x - y] % M;
  };
  auto A = [&](ll x, ll y) { return frac[x] * inv_frac[x - y] % M; };
  // Contribution of 1
  ll one = (A(n * 2, n * 2) * 2) % M;
  one = (one + M - A(n, n) - 1) % M;
  auto re = [&](ll &val) { val = (val % M + M) % M; };
  re(one);
  // Another calculation of two
  ll two = 2 * C(2 * n, n) % M * A(2 * n, 2 * n) % M * A(n, n) % M;
  for (int i = 0; i <= n; ++i) {
    two -= C(n, i) * C(n, n - i) % m * C(2 * n - i, n) % m * A(n, n) % M *
           A(n, n) % M * A(n, n) % m;
    re(two);
  }
  two -= one + 1;
  two = (two + M) % M;
  re(two);
  // // Contribution of 3
  // ll three = 0;
  // for (int i = 1; i <= 1; ++i) {
  //   for (int j = 1; j <= 1; ++j) {
  //     three = three + (C(n, i) * A(n, i) % M) * (C(n, j) * A(n, j) % M) % M *
  //                         A(n * 3 - i - j, n * 3 - i - j) % M;
  //     three = three >= M ? three - M : three;
  //   }
  // }
  // ll two = (frac[n * 3] + M - (one + three) % M - 1) % M;
  // two = (two + M) % M;
  ll three = (frac[n * 3] + M - (one + two + 1) % M) % M;
  re(three);
  // cout << one << " " << two << " " << three << "\n";
  cout << (one + two * 2 % M + three * 3 % M) % M << "\n";
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
