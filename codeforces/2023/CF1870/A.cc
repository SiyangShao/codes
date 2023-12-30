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
  int n, k, x;
  cin >> n >> k >> x;
  if (x < k - 1 || n < k) {
    cout << "-1\n";
    return;
  }
  ll ans = (ll)(k - 1) * k / 2;
  if (x == k) {
    ans += (ll)(k - 1) * (n - k);
  } else {
    ans += (ll)x * (n - k);
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