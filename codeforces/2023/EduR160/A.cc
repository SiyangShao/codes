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
  int n = (int)s.length();
  for (int i = 1; i + 1 <= n; ++i) {
    string lef = s.substr(0, i);
    string rig = s.substr(i, n - i);
    if (lef[0] == '0' || rig[0] == '0')
      continue;
    ll l = stoll(lef), r = stoll(rig);
    if (l < r) {
      cout << l << " " << r << "\n";
      return;
    }
  }
  cout << "-1\n";
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