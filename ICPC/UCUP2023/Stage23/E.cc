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
  int n, d;
  cin >> n >> d;
  vector<ll> a(n);
  ll sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  if (d == 1) {
    ll ans = sum * (sum - 1) / 2;
    cout << ans << "\n";
  } else if (d == 2) {
    ll base = sum * (sum - 1) / 2;
    for (auto i : a) {
      base -= i * (i - 1) / 2;
    }
    cout << base << "\n";
  } else {
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += a[i] * (n - i - 1);
    }
    cout << ans << "\n";
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