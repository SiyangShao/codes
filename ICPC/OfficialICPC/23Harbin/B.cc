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
  ll sum = 0;
  bool posFlag = false, negFlag = false;
  for (auto i : a) {
    sum += i;
    if (sum > 0) {
      cout << "+";
    } else if (sum == 0) {
      if (posFlag)
        cout << "+";
      else if (negFlag)
        cout << "-";
      else
        cout << "0";
    } else {
      cout << "-";
    }
    if ((sum % 2 == 1) && (!posFlag) && (!negFlag)) {
      if (sum > 0) {
        posFlag = true;
      } else if (sum < 0) {
        negFlag = true;
      }
    }
    sum >>= 1;
  }
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