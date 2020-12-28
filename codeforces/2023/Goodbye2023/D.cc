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
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  vector<int> num(n, 0);
  num[0] = 1;
  num[1] = 9;
  num[2] = 6;
  for (auto j : num) {
    cout << j;
  }
  cout << "\n";
  num[0] = num[1] = num[2] = 0;
  for (int i = 1; i <= (n - 1) / 2; ++i) {
    num[0] = 9;
    num[0 + i] = 6;
    num[0 + i + i] = 1;
    for (auto j : num) {
      cout << j;
    }
    cout << "\n";
    num[0] = num[0 + i] = num[0 + i + i] = 0;
    num[0] = 1;
    num[0 + i] = 6;
    num[0 + i + i] = 9;
    for (auto j : num) {
      cout << j;
    }
    cout << "\n";
    num[0] = num[0 + i] = num[0 + i + i] = 0;
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