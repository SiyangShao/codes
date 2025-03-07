#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...)                                                               \
  {}
#endif
using namespace std;
using ll = long long;
auto check(ll x, ll y, ll z, ll k, ll t) {
  if (t <= 0) {
    return ll(1e18);
  }
  // target: t
  ll base = t * x;
  ll step = t / k;
  // k, 2k, 3k, ....
  z -= (k + k * step) * step / 2;
  base += step * y;
  z = max(z, 0LL);
  base += (z + t - 1) / t * y;
  return base;
}
auto solve() {
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  // enumerate possible step
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
