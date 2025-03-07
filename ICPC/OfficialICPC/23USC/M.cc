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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<set<ll>> vec(n + 5);
  vec[0].emplace(0);
  for (int i = 0; i < n; ++i) {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    vector<pair<ll, ll>> add;
    for (auto j = l1; j <= r1; ++j) {
      if (j < x || j >= x + n) {
        continue;
      }
      while (true) {
        auto it = vec[j - x].lower_bound(l2 - y);
        if (it == vec[j - x].end() || *it > (r2 - y)) {
          break;
        }
        auto k = *it;
        vec[j - x].erase(it);
        add.emplace_back(j - x, k + 1);
        add.emplace_back(j - x + 1, k);
        // vec[j - x].emplace(k + 1);
        // vec[j - x + 1].emplace(k);
        // dbg(j, k, vec[j - x], vec[j - x + 1]);
      }
    }
    for (auto [j, k] : add) {
      vec[j].emplace(k);
    }
  }

  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (vec[i].empty()) {
      continue;
    }
    auto lst = *vec[i].rbegin();
    ans = max(ans, lst + i);
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