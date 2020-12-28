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
  string s;
  cin >> s;
  int zero = 0, one = 0;
  for (auto i : s) {
    if (i == '0')
      zero++;
    else
      one++;
  }
  for (auto i : s) {
    if (i == '0') {
      if (one == 0) {
        cout << zero << "\n";
        return;
      }
      one--;
    } else {
      if (zero == 0) {
        cout << one << "\n";
        return;
      }
      zero--;
    }
  }
  cout << "0\n";
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