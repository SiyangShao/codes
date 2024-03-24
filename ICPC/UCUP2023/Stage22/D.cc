#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
// -1 - 2 * (n-2) + 2 * y = y
//
auto solve() {
  int n;
  cin >> n;
  int y = 1 + 2 * (n - 2);
  cout << "1 ";
  for (int i = 1; i < n; ++i) {
    cout << "-1 2 ";
  }
  cout << y << "\n";
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