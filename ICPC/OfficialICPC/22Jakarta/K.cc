#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
[[maybe_unused]] auto someFunction(vector<ll> &A, int n, int k) {
  auto B = A;
  ll cnt = 1;
  for (int i = 0; i < k; ++i) {
    A = B;
    for (int j = 0; j < n; ++j) {
      B[j] = A[j] * A[(j + cnt) % n];
    }
    cnt = cnt * 2 % MOD;
  }
  return B;
}
constexpr ll MODmi = MOD - 1;
auto cal(ll k, ll n) {
  pair<ll, ll> res = {0, 1};
  pair<ll, ll> input = {2 / n, 2 % n};
  auto mul = [=](pair<ll, ll> x, pair<ll, ll> y) {
    auto [p1, q1] = x;
    auto [p2, q2] = y;
    ll p = p1 * p2 % MODmi * n % MODmi + p1 * q2 % MODmi + q1 * p2 % MODmi;
    p = p % MODmi;
    ll q = q1 * q2;
    p += q / n;
    q = q % n;
    return pair{p, q};
  };
  while (k) {
    if (k & 1) {
      res = mul(res, input);
    }
    input = mul(input, input);
    k >>= 1;
  }
  return res;
}
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  // auto b = someFunction(a, n, k);
  // for (auto i : b) {
  //   cout << i << " ";
  // }
  // cout << "\n";
  auto [p, q] = cal(k, n);
  ll common = 1;
  for (auto i : a) {
    common = common * i % MOD;
  }
  common = qpow(common, p);
  vector<ll> b(n * 2 + 1);
  b[0] = 1;
  for (int i = 1; i <= n * 2; ++i) {
    if (i <= n)
      b[i] = a[i - 1];
    else
      b[i] = a[i - n - 1];
    b[i] = b[i] * b[i - 1] % MOD;
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i + q] * qpow(b[i], MOD - 2) % MOD * common % MOD << " ";
  }
  cout << "\n";
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