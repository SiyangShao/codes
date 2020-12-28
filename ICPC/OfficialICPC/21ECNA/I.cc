#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
auto solve() {
  int p1, p2, u1, u2;
  cin >> p1 >> u1;
  int n = p1 + u1;
  vector<int> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  cin >> p2 >> u2;
  for (auto &i : b)
    cin >> i;
  vector<int> pos(n + 1, 0);
  for (int i = 0; i < p2; ++i) {
    pos[b[i]] = 1;
  }
  for (int i = p2; i < n; ++i) {
    pos[b[i]] = 2;
  }
  int ans = 0;
  int p = 0;
  for (int i = 0; i < p1; ++i) {
    if (pos[a[i]] == 2) {
      ans++;
    } else if (p < n && a[i] == b[p]) {
      p++;
    } else {
      ans += 2;
    }
  }
  p = n - 1;
  for (int i = n - 1; i >= p1; --i) {
    if (pos[a[i]] == 1) {
      ans++;
    } else if (p >= 0 && a[i] == b[p]) {
      p--;
    } else {
      ans += 2;
    }
  }
  cout << ans << "\n";
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