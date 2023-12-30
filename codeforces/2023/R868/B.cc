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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % k != i % k) {
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << "0\n";
  } else if (cnt == 2) {
    cout << "1\n";
  } else {
    cout << "-1\n";
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