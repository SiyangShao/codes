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
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  vector<vector<int>> pos(10);
  for (int i = 0; i < n; ++i) {
    pos[a[i]].emplace_back(i);
  }
  ll ans = 0;
  multiset<ll> cur;
  vector<vector<ll>> del(n + 1);
  for (int i = 0; i < 10; ++i) {
    for (auto j : pos[i]) {
      for (int dif = -10; dif <= 10; ++dif) {
        if (i + dif * 2 >= 10 || i + dif * 2 < 0)
          continue;
        auto mid = upper_bound(pos[i + dif].begin(), pos[i + dif].end(), j);
        if (mid == pos[i + dif].end())
          continue;
        auto rig =
            upper_bound(pos[i + dif * 2].begin(), pos[i + dif * 2].end(), *mid);
        if (rig == pos[i + dif * 2].end())
          continue;
        dbg(j, *rig);
        ll len = n - *rig;
        del[j + 1].emplace_back(len);
        cur.emplace(len);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (auto len : del[i]) {
      cur.erase(cur.find(len));
    }
    if (!cur.empty())
      ans += *cur.rbegin();
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