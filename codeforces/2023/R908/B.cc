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
auto real_solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a, b(m);
  a.emplace_back(1e9);
  for (int i = 0; i < n; ++i) {
    int u;
    cin >> u;
    a.emplace_back(u);
  }
  n += 2;
  a.emplace_back(-1e9);
  multiset<int> newb;
  for (auto &i : b) {
    cin >> i;
    newb.emplace(i);
  }
  vector<int> x;
  for (int i = 0; i + 1 < n; ++i) {
    x.emplace_back(a[i]);
    auto it = newb.upper_bound(a[i]);
    if (it == newb.begin())
      continue;
    it = prev(it);
    dbg(*it);
    set<int> del;
    while (*it >= a[i + 1]) {
      x.emplace_back(*it);
      del.emplace(*it);
      if (it == newb.begin())
        break;
      it = prev(it);
    }
    for (auto iit : del) {
      newb.erase(iit);
    }
  }
  assert(newb.empty());
  x.emplace_back(a[n - 1]);
  for (int i = 1; i + 1 < (int)x.size(); ++i) {
    cout << x[i] << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    real_solve();
  }
}