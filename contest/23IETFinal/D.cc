#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
ld f(ld x) {
  // return x * sin(x * x);
  return 0.125 *
         ((x * (3 * x * x + 5)) / ((x * x + 1) * (x * x + 1)) + 3 * atan(x));
  // return -0.5 * cos(x * x);
}
auto solve() {
  ld x, y;
  cin >> x >> y;
  ld R = f(y), L = f(x);
  cout << setprecision(10) << R - L << "\n";
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