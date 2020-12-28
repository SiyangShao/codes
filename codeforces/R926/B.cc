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
  ll n, k;
  cin >> n >> k;
  if (k <= n * 2) {
    cout << (k + 1) / 2 << "\n";
  } else {
    k -= n * 2;
    if (k <= 2 * n - 4) {
      cout << (k + 1) / 2 + n << "\n";
    } else if (k == 2 * n - 3) {
      cout << n * 2 - 1 << "\n";
    } else {
      cout << n * 2 << "\n";
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