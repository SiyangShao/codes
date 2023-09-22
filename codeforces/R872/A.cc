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
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  int lef = 0, rig = 0;
  vector<int> a;
  for (auto &i : x) {
    cin >> i;
    if (i == -1)
      lef++;
    if (i == -2)
      rig++;
    if (i > 0)
      a.emplace_back(i);
  }
  {
    ranges::sort(a);
    auto [fi, ls] = ranges::unique(a);
    a.erase(fi, ls);
  }
  int ans = max(lef + (int)a.size(), rig + (int)a.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    int l = min(a[i] - 1, i + lef);
    int r = min(m - a[i], (int)a.size() - i - 1 + rig);
    ans = max(ans, l + r + 1);
  }
  ans = min(ans, m);
  cout << ans << "\n";
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