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
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> dir(n);
  dir[0] = 1, dir[n - 1] = -1;
  for (int i = 1; i < n - 1; ++i) {
    int lef = a[i] - a[i - 1], rig = a[i + 1] - a[i];
    if (lef < rig) {
      dir[i] = -1;
    } else {
      dir[i] = 1;
    }
  }
  dbg(dir);
  vector<int> disL(n), disR(n);
  for (int i = 1; i < n; ++i) {
    if (dir[i - 1] == 1) {
      disL[i] = disL[i - 1] + 1;
    } else {
      disL[i] = disL[i - 1] + a[i] - a[i - 1];
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (dir[i + 1] == -1) {
      disR[i] = disR[i + 1] + 1;
    } else {
      disR[i] = disR[i + 1] + a[i + 1] - a[i];
    }
  }
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x < y) {
      cout << disL[y] - disL[x] << "\n";
    } else {
      cout << disR[y] - disR[x] << "\n";
    }
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