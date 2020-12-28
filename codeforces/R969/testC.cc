#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
bool can(set<ll> &d) {
  for (auto x : d) {
    for (auto y : d) {
      if (x % 2 != y % 2)
        continue;
      ll mid = (x + y) / 2;
      if (!d.contains(mid)) {
        d.emplace(mid);
        return can(d);
      }
    }
  }
  bool val = true;
  for (auto it = d.begin(); it != d.end(); ++it) {
    auto nxt = next(it);
    if (nxt == d.end())
      break;
    if ((*nxt - *it) != 1) {
      dbg(d);
      val = false;
      break;
    }
  }
  
  return val;
}
auto check(ll x, ll y, ll z) {
  assert(x <= y && y <= z);
  if (y - x == z - y && (z - y) % 2 == 0)
    return false;
  set<ll> v;
  v.emplace(x), v.emplace(y), v.emplace(z);
  return can(v);
}
auto solve() {
  for (int i = 1; i <= 150; ++i) {
    for (int j = i + 1; j <= 150; ++j) {
      for (int k = j + 1; k <= 150; ++k) {
        if (!check(i, j, k)) {
          cout << i << " " << j << " " << k << " diff i-j:" << i - j
               << " diff j-k:" << j - k << endl;
        }
      }
    }
  }
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