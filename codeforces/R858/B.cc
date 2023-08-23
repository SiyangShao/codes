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
  vector<int> a(n);
  int zero = 0, one = 0;
  for (auto &i : a) {
    cin >> i;
    if (i == 0)
      zero++;
    if (i == 1)
      one++;
  }
  if (zero <= (n + 1) / 2) {
    cout << "0\n";
  } else {
    if (zero == n) {
      cout << "1\n";
    } else if (n == zero + one) {
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
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