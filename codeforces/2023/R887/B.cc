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
  for (auto &i : a)
    cin >> i;
  vector<int> ans(n);
  deque<pair<int, int>> dq(n);
  for (int i = 0; i < n; ++i) {
    dq[i] = {a[i], i};
  }
  ranges::sort(dq);
  int val = n, l = 0, r = n - 1;
  while (!dq.empty()) {
    if ((dq.rbegin()->first == n - l) ^ (dq.begin()->first == n - 1 - r)) {
      if (dq.rbegin()->first == n - l)
        ans[dq.rbegin()->second] = val--, dq.pop_back(), r--;
      else
        ans[dq.begin()->second] = -(val--), dq.pop_front(), l++;
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (auto i : ans) {
    cout << i << " ";
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