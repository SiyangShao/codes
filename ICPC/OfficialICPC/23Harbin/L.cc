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
  vector<int> a(n), b(n), pos(n);
  for (auto &i : a)
    cin >> i, i--;
  for (auto &i : b)
    cin >> i, i--;
  for (int i = 0; i < n; ++i)
    pos[b[i]] = i;
  vector<int> sorted;
  for (int i = 0; i < n; ++i) {
    int cur = pos[a[i]];
    int po =
        (int)(lower_bound(sorted.begin(), sorted.end(), cur) - sorted.begin());
    int num = n - i - 1 + po;
    for (int j = 0; j < num; ++j)
      cout << "2";
    for (int j = 0; j < n - num; ++j)
      cout << "1";
    sorted.emplace_back(cur);
    sort(sorted.begin(), sorted.end());
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