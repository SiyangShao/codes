#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
const string base = "FBFFBFFB";
const string x = base + base + base + base;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i + n < x.length(); ++i) {
    if (s == x.substr(i, n)) {
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