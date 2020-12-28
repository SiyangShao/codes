#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
bool judge(string &x, string &y) {
  int n = static_cast<int>(x.length());
  int ax = 0, bx = 0, cx = 0;
  for (auto i : x) {
    if (i == 'A')
      ax++;
    else if (i == 'B')
      bx++;
    else
      cx++;
  }
  int ay = 0, by = 0;
  for (auto i : y) {
    if (i == 'A')
      ay++;
    else
      by++;
  }
  if (ax + cx < ay || bx + cx < by || ax > ay || bx > by)
    return false;
  int cnt = ay - ax;
  ax = 0;
  for (int i = 0; i < n; ++i) {
    if (x[i] == 'A')
      ax++;
    else if (x[i] == 'C' and cnt) {
      ax++;
      cnt--;
    }
    if (y[i] == 'A')
      ax--;
    if (ax < 0)
      return false;
  }
  return true;
}
auto solve() {
  int n;
  string x, y;
  cin >> n >> x >> y;
  string a, b;
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if (y[i] == 'C') {
      if (x[i] != 'C') {
        cout << "No\n";
        return;
      }
      flag = flag and judge(a, b);
      a = "", b = "";
    } else {
      a += x[i];
      b += y[i];
    }
  }
  flag = flag and judge(a, b);
  cout << (flag ? "Yes\n" : "No\n");
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