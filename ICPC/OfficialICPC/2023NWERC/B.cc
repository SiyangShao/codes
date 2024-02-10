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
ld square(ld x) { return x * x; }
auto solve() {
  ld h, r, a, w;
  cin >> h >> r >> a >> w;
  ld ans = sqrt(square(a * h / (w - a)) + a * square(h) / (w - a)) / 2;
  cout << fixed << setprecision(16) << ans << "\n";
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