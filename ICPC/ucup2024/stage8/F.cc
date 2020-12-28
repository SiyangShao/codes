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
  vector<string> s(n);
  vector<int> a(n), rk(n), val(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> a[i];
    val[i] = a[i];
  }
  sort(val.begin(), val.end());
  for (int i = 0; i < n; ++i) {
    auto it = upper_bound(val.begin(), val.end(), a[i]);
    rk[i] = (int)(val.end() - it);
  }
  cout << "Stage: ";
  bool first = true;
  for (int i = 0; i < n; ++i) {
    int sz = (int)s[i].length();
    sz -= rk[i] + 1;
    if (sz < 0)
      sz = 0;
    for (int j = 0; j < sz; ++j) {
      if (first) {
        first = false;
        s[i][j] = s[i][j] - 'a' + 'A';
      }
      cout << s[i][j];
    }
  }
  cout << "\n";
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