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
  int xk, yk, xq, yq;
  cin >> xk >> yk >> xq >> yq;
  set<pair<int, int>> stx, sty;
  stx.emplace(xk - a, yk - b);
  stx.emplace(xk - a, yk + b);
  stx.emplace(xk + a, yk + b);
  stx.emplace(xk + a, yk - b);
  sty.emplace(xq - a, yq - b);
  sty.emplace(xq - a, yq + b);
  sty.emplace(xq + a, yq + b);
  sty.emplace(xq + a, yq - b);
  swap(a, b);
  stx.emplace(xk - a, yk - b);
  stx.emplace(xk - a, yk + b);
  stx.emplace(xk + a, yk + b);
  stx.emplace(xk + a, yk - b);
  sty.emplace(xq - a, yq - b);
  sty.emplace(xq - a, yq + b);
  sty.emplace(xq + a, yq + b);
  sty.emplace(xq + a, yq - b);
  int ans = 0;
  for (auto i : stx) {
    if (sty.contains(i))
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