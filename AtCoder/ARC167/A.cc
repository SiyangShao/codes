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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  ranges::sort(a, greater<>());
  for (int i = m; i < n; ++i) {
    a[m - 1 - (i - m)] += a[i];
  }
  ll ans = 0;
  for (int i = 0; i < m; ++i) {
    ans += a[i] * a[i];
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