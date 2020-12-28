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
  vector<int> lef(n), rig(n);
  for (auto &i : a)
    cin >> i;
  for (int i = 0; i < n; ++i) {
    lef[i] = i - 1, rig[i] = i + 1;
  }
  auto canDel = [&](int i) {
    return (lef[i] != -1 && a[lef[i]] == a[i] - 1) ||
           (rig[i] != n && a[rig[i]] == a[i] - 1);
  };
  priority_queue<pair<int, int>> Q;
  vector<int> del(n);
  for (int i = 0; i < n; ++i) {
    if (canDel(i))
      Q.emplace(a[i], i);
  }
  while (!Q.empty()) {
    auto [_, i] = Q.top();
    Q.pop();
    if (del[i])
      continue;
    del[i] = 1;
    if (lef[i] != -1) {
      rig[lef[i]] = rig[i];
      if (canDel(lef[i]))
        Q.emplace(a[lef[i]], lef[i]);
    }
    if (rig[i] != n) {
      lef[rig[i]] = lef[i];
      if (canDel(rig[i]))
        Q.emplace(a[rig[i]], rig[i]);
    }
  }
  if (count(del.begin(), del.end(), 1) != n - 1 ||
      *min_element(a.begin(), a.end()) != 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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