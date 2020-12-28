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
  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
  }
  ll cnt = 0;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    ll ans = 0;
    if (l == 0)
      ans = a[r];
    else
      ans = a[r] - a[l - 1];
    if (ans >= 0) {
      cnt += ans;
    }
  }
  cout << cnt << "\n";
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