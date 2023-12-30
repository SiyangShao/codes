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

  if (n == 1) {
    cout << "1\n";
  } else if (n % 2 == 1) {
    cout << "-1\n";
  } else {
    for (int i = 0; i < n / 2; ++i) {
      cout << i * 2 + 2 << " " << i * 2 + 1 << " ";
    }
    cout << "\n";
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