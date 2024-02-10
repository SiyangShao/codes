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
  int a, b;
  cin >> a >> b;
  int x = 0, y = 0;
  for (int i = a; i <= b; ++i) {
    string s;
    cin >> s;
    if (s == "Fizz") {
      x = gcd(x, i);
    } else if (s == "Buzz") {
      y = gcd(y, i);
    } else if (s == "FizzBuzz") {
      x = gcd(x, i);
      y = gcd(y, i);
    } else {
      continue;
    }
  }
  dbg(x, y);
  if (x == 0)
    x = b + 1;
  if (y == 0)
    y = b + 2;
  cout << x << " " << y << "\n";
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