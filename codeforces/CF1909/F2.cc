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
constexpr int N = 2e5 + 7;
array<ll, N> frac, invFrac;
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
void init() {
  frac[0] = 1;
  for (int i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  invFrac[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) {
    invFrac[i] = invFrac[i + 1] * (i + 1) % MOD;
  }
  assert(invFrac[0] == 1);
}
ll A(ll x, ll y) {
  if (x < y)
    return 0;
  return frac[x] * invFrac[x - y] % MOD;
}
ll C(ll x, ll y) {
  if (x < y)
    return 0;
  return A(x, y) * invFrac[y] % MOD;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  if (a[n - 1] == -1) {
    a[n - 1] = n;
  }
  if (a.back() != n) {
    cout << "0\n";
    return;
  }
  ll ans = 1;
  int prex = 0, prey = 0;
  auto upd = [&](int x, int y) {
    if (ans == 0)
      return;
    ll cur = 0;
    for (int i = 0; i <= y - prey; ++i) {
      cur += C(x - prex, i) * A(prex - prey, i) % MOD *
             C(x - prex, y - prey - i) % MOD * A(x - prey - i, y - prey - i) %
             MOD;
      cur %= MOD;
    }
    prex = x, prey = y;
    ans = ans * cur % MOD;
  };
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1)
      continue;
    upd(i + 1, a[i]);
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}