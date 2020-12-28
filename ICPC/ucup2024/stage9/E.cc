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
  vector<string> mp(n);
  vector<int> deg(n);
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    cin >> mp[i];
    for (auto j : mp[i]) {
      if (j == '1') {
        deg[i]++;
      }
    }
  }
  int idx = -1;
  for (int i = 0; i < n; ++i) {
    if (idx == -1 || deg[i] > deg[idx]) {
      idx = i;
    }
  }
  ans.emplace_back(idx);
  if (deg[idx] == n - 1) {
    cout << "NOT FOUND\n";
    return;
  }
  idx = -1;
  for (int i = 0; i < n; ++i) {
    if (mp[i][ans[0]] == '1') {
      if (idx == -1 || deg[i] > deg[idx]) {
        idx = i;
      }
    }
  }
  ans.emplace_back(idx);
  // for all points point to idx
  idx = -1;
  for (int i = 0; i < n; ++i) {
    if (i == ans[0] || i == ans[1]) {
      continue;
    }
    if (mp[i][ans[1]] == '1') {
      if (idx == -1 || deg[i] > deg[idx]) {
        idx = i;
      }
    }
  }
  ans.emplace_back(idx);
  for (auto i : ans) {
    assert(i != -1);
    cout << i + 1 << ' ';
  }
  cout << "\n";
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