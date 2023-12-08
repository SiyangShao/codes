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
  vector<int> lef(n + 2), rig(n + 2);
  for (int i = 1; i <= n; ++i) {
    lef[i] = i - 1 + a[i - 1];
    rig[i] = (n - i) + a[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    lef[i] = max(lef[i], lef[i + 1]);
  }
  for (int i = 1; i <= n; ++i) {
    rig[i] = max(rig[i], rig[i - 1]);
  }
  dbg(lef, rig);
  constexpr int inf = 2e9;
  int ans = inf;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, max({a[i - 1], lef[i + 1], rig[i - 1]}));
  }
  cout << ans << "\n";
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