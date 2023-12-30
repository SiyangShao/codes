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
  for (int i = 0; i < n; ++i) {
    int j = n - i;
    if (i * (i - 1) / 2 + j * (j - 1) / 2 == m) {
      cout << "YES\n";
      for (int k = 0; k < i; ++k) {
        cout << 1 << " ";
      }
      for (int k = 0; k < j; ++k) {
        cout << -1 << " ";
      }
      cout << "\n";
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