#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector mp(m, vector(n, 0LL));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mp[j][i];
    }
  }
  ll ans = 0;
  for (int j = 0; j < m; ++j) {
    auto &vec = mp[j];
    sort(vec.begin(), vec.end());
    for (ll i = 0; i < n; ++i) {
      ans += -(n - i - 1LL) * vec[i] + i * vec[i];
    }
  }
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