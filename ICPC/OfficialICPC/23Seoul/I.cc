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
  vector<pair<ll, ll>> p(n);
  for (auto &[l, r] : p) {
    cin >> l >> r;
  }
  ll cnt = 0, cur = 0;
  reverse(p.begin(), p.end());
  for (auto [l, r] : p) {
    if (l > cur) {
      cnt++;
      cur = r;
    } else if (r < cur) {
      cur = r;
    }
  }
  cout << cnt << '\n';
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