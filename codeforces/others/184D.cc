#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll qpow(ll x, ll y, const ll MOD) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
ll f(ll x, ll k, ll p) {
  return (k % p == 0 ? 0 : qpow(k, qpow(2, x, p - 1), p));
}
auto solve() {
  ll k, l, r, p;
  cin >> k >> l >> r >> p;
  if (p == 2) {
    if (k % 2 == 1) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  } else {
    ll t = (f(l, k, p) == 1 ? qpow(2, r - l + 1, p)
                            : (1ll * (f(r + 1, k, p) - 1 + p) % p *
                               qpow((f(l, k, p) - 1 + p) % p, p - 2, p) % p));
    if (k % 2 == 1) {
      t = t * qpow(qpow(2, r - l, p), p - 2, p) % p;
    }
    cout << t << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}