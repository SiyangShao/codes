#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
vector<int> LIS(vector<int> &nums) {
  vector<int> lis;
  for (auto i : nums) {
    auto it = lower_bound(lis.begin(), lis.end(), i);
    if (it == lis.end()) {
      lis.emplace_back(i);
    } else {
      *it = i;
    }
  }
  return lis;
}
auto solve() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  // for (auto &i : b) {
  // cin >> i;
  // }
  cout << LIS(a).size() << "\n";
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