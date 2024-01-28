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
  for (auto &i : a)
    cin >> i;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (n % i != 0)
      continue;
    int div = 0;
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k + 1 < n / i; ++k) {
        div = gcd(div, abs(a[k * i + j] - a[k * i + j + i]));
        if (div == 1)
          break;
      }
      if (div == 1)
        break;
    }
    if (div != 1)
      ans++;
  }
  cout << ans << "\n";
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