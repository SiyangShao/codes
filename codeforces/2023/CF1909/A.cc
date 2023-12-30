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
  int n;
  cin >> n;
  vector<pair<int, int>> point(n);
  vector<bool> flag(4, true);
  for (auto &[x, y] : point) {
    cin >> x >> y;
    if (x > 0)
      flag[0] = false;
    if (x < 0)
      flag[1] = false;
    if (y > 0)
      flag[2] = false;
    if (y < 0)
      flag[3] = false;
  }
  for (auto i : flag) {
    if (i) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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