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
  int n, m;
  cin >> n >> m;
  vector<unsigned int> a(n), b(m);
  unsigned int base = 0;
  for (auto &i : a) {
    cin >> i;
    base = base ^ i;
  }
  unsigned int ans = base;
  for (auto &i : b) {
    cin >> i;
  }
  if (n % 2 == 1) {
    for (auto i : b) {
      ans = ans | i;
    }
  } else {
    for (auto i : b) {
      ans = ans & (~i);
    }
  }
  cout << min(ans, base) << " " << max(ans, base) << "\n";
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