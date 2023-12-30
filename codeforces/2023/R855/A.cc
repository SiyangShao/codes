#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using i64 = long long;
auto solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int status = 0;
  if ((s[0] != 'M' && s[0] != 'm') || (s[n - 1] != 'w' && s[n - 1] != 'W')) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'M' || s[i] == 'm') {
      if (status != 0) {
        std::cout << "NO\n";
        return;
      }
    } else if (s[i] == 'E' || s[i] == 'e') {
      if (status == 0)
        status++;
      if (status != 1) {
        std::cout << "NO\n";
        return;
      }
    } else if (s[i] == 'O' || s[i] == 'o') {
      if (status == 1)
        status++;
      if (status != 2) {
        std::cout << "NO\n";
        return;
      }
    } else if (s[i] == 'W' || s[i] == 'w') {
      if (status == 2)
        status++;
      if (status != 3) {
        std::cout << "NO\n";
        return;
      }
    } else {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  while (_--) {
    solve();
  }
}