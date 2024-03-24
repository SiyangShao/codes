// 就算大雨让这座城市颠倒
// 我会给你回报
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
  vector<ll> a(n * 2);
  for (auto &i : a)
    cin >> i;
  ranges::sort(a);
  ll ans = 0;
  for (int i = 0; i < n * 2; i += 2) {
    ans += a[i];
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