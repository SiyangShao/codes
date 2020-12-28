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
  map<ll, multiset<ll>> mp1, mp2;
  ll maxw = 0, maxh = 0;
  ll area = 0;
  for (int i = 1; i <= n; i++) {
    ll x, y;
    cin >> x >> y;
    mp1[x].insert(y);
    mp2[y].insert(x);
    maxw = max(maxw, x);
    maxh = max(maxh, y);
    area += (ll)x * y;
  }
  set<array<ll, 2>> ans;
  auto check = [](int n, ll W, ll H, int idx, map<ll, multiset<ll>> mp1,
                  map<ll, multiset<ll>> mp2) {
    while (W > 0 && H > 0) {
      ll tot = 0;
      if (idx == 0) // W
      {
        for (auto it : mp1[W]) {
          tot += it;
          n--;
          mp2[it].erase(mp2[it].find(W));
        }
        H -= tot;
        idx = 1 - idx;
      } else // H
      {
        for (auto it : mp2[H]) {
          tot += it;
          n--;
          mp1[it].erase(mp1[it].find(H));
        }
        W -= tot;
        idx = 1 - idx;
      }
      if (tot == 0)
        return false;
    }
    if (n != 0)
      return false;
    return true;
  };
  if (area % maxw == 0 && check(n, maxw, area / maxw, 0, mp1, mp2)) {
    ans.insert({maxw, area / maxw});
  }
  if (area % maxh == 0 && check(n, area / maxh, maxh, 1, mp1, mp2)) {
    ans.insert({area / maxh, maxh});
  }
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x << " " << y << '\n';
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