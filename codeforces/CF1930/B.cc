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
  deque<int> odd, even;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1)
      odd.emplace_back(i);
    else
      even.emplace_back(i);
  }
  reverse(even.begin(), even.end());
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      cout << odd.front() << " ";
      odd.pop_front();
    } else {
      cout << even.front() << " ";
      even.pop_front();
    }
  }
  cout << "\n";
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