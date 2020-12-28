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
  map<multiset<int>, int> mp;
  for (int i = 10000; i < 100000; ++i) {
    int x = (int)sqrt(i);
    if (x * x == i) {
      // cout << i << "\n";
      multiset<int> tmp;
      int y = i;
      while (y) {
        tmp.emplace(y % 10);
        y /= 10;
      }
      mp[tmp]++;
      if (tmp == multiset{0, 0, 1, 6, 9}) {
        cout << i << "\n";
      }
    }
  }
  for (auto [st, cnt] : mp) {
    if (cnt >= 5) {
      dbg(st);
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