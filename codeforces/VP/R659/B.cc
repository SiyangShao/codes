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
  vector<int> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (int msk = 30; msk >= 0; msk--) {
    int one = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
      b[i] = (a[i] >> msk) & 1;
      if (b[i])
        one++;
      else
        zero++;
    }
    if (one % 2 == 0)
      continue;
    if (one % 4 == 1) {
      cout << "WIN\n";
    } else {
      if (zero % 2 == 1) {
        cout << "WIN\n";
      } else {
        cout << "LOSE\n";
      }
    }
    return;
  }
  cout << "DRAW\n";
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