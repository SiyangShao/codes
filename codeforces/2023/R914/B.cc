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
  vector<int> a(n), id(n), ans(n);
  for (auto &i : a) {
    cin >> i;
  }
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int i, int j) { return a[i] < a[j]; });
  ll curSum = 0;
  auto it = id.begin(), pre = id.begin();
  while (it != id.end()) {
    if (curSum >= a[*it]) {
      curSum += a[*it];
      it++;
    } else {
      while (pre != it) {
        ans[*pre] = (int)(it - id.begin());
        pre++;
      }
      curSum += a[*it];
      it++;
    }
  }
  while (pre != it) {
    ans[*pre] = (int)(it - id.begin());
    pre++;
  }
  for (auto i : ans) {
    cout << i - 1 << " ";
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