#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
bool check(ll x, ll k) {
  ll res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }
  return res % k == 0;
}
auto solve() {
  ll x, k;
  cin >> x >> k;
  for (ll i = x; i <= x + 100; ++i) {
    if (check(i, k)) {
      cout << i << "\n";
      return;
    }
  }
  assert(false);
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