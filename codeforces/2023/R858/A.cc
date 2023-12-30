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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (d < b) {
    cout << "-1\n";
    return;
  }
  ll dif = d - b;
  a += dif;
  if (a < c) {
    cout << "-1\n";
    return;
  }
  dif += a - c;
  cout << dif << "\n";
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