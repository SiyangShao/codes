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
  string s;
  cin >> s;
  int b = 0;
  for (auto i : s) {
    if (i == 'B')
      b++;
  }
  if (b == k) {
    cout << "0\n";
    return;
  }
  if (k == 0) {
    cout << "1\n";
    cout << n << " "
         << "A"
         << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    b -= (s[i] == 'B' ? 1 : 0);
    if (b + i + 1 == k) {
      cout << "1\n";
      cout << i + 1 << " "
           << "B"
           << "\n";
      return;
    }
    if (b == k) {
      cout << "1\n";
      cout << i + 1 << " "
           << "A"
           << "\n";
      return;
    }
  }
  cout << "2\n";
  cout << n << " "
       << "A"
       << "\n";
  cout << k << " "
       << "B"
       << "\n";
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