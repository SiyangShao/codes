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
  cout << 5 << " " << 5 << "\n";
  for (int i = 0; i < 5; ++i) {
    cout << rand() % 100 << " ";
  }
  cout << "\n";
  for (int i = 0; i < 5; ++i) {
    cout << rand() % 100 << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 100;
  cout << _ << "\n";
  while (_--) {
    solve();
  }
}