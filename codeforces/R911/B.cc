#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int a, b, c;
  cin >> a >> b >> c;
  auto check = [](int x, int y, int z) {
    // change y and z to x
    if (y < z)
      swap(y, z);
    // y >= z
    int dif = y - z;
    if (dif % 2 == 1)
      return false;
    return true;
  };
  cout << check(a, b, c) << " " << check(b, a, c) << " " << check(c, a, b)
       << "\n";
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