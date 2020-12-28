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
  string a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (c[i] != a[i]) {
        cout << "YES\n";
        return;
      }
    } else {
      if (c[i] != a[i] && c[i] != b[i]) {
        cout << "YES\n";
        return;
      }
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