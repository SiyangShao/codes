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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  int cnt = 0;
  for (auto i : a) {
    if (i == 0) {
      cout << "0\n";
      return;
    }
    if (i < 0) {
      cnt++;
    }
  }
  if (cnt % 2 == 0) {
    cout << "1\n";
    cout << "1 0"
         << "\n";
  } else {
    cout << "0\n";
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