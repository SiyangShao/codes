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
  string cur = "ietntu";
  int pos = 0;
  for (auto i : s) {
    if (i == cur[pos]) {
      pos++;
    }
    if (pos == 6) {
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