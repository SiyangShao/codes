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
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (auto &i : d)
    cin >> i;
  vector<int> t(m);
  for (auto &i : t)
    cin >> i;
  int s = -1;
  for (int i = 0; i < n; ++i) {
    if (d[i] == t[0]) {
      s = i;
      break;
    }
  }
  assert(s != -1);
  bool flag = true;
  for (int i = 0; i < m; ++i) {
    int j = s + i;
    if (j >= n)
      j -= n;
    if (d[j] != t[i]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "1\n";
    return;
  }
  for (int i = 0; i < m; ++i) {
    int j = s - i;
    if (j < 0) {
      j += n;
    }
    if (d[j] != t[i]) {
      cout << "0\n";
      return;
    }
  }
  cout << "1\n";
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