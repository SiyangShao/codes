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
  string s;
  cin >> s;
  ll x = 0, y = 0;
  for (auto i : s) {
    if (i == '+') {
      if (y > 0)
        y--;
      else
        x++;
    } else {
      if (x > 0)
        x--;
      else
        y++;
    }
  }
  cout << max(x, y) << "\n";
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