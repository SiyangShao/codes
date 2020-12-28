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
  ll n, k;
  cin >> n >> k;
  vector<ll> c(n);
  ll ans = 1;
  for (auto &i : c) {
    cin >> i;
    ans = lcm(ans, i) % k;
  }
  if (ans) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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