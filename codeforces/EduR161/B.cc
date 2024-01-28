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
  for (auto &i : a)
    cin >> i;
  vector<ll> num(n + 1, 0);
  for (auto i : a) {
    num[i]++;
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (num[i] >= 3) {
      ans += num[i] * (num[i] - 1) * (num[i] - 2) / 6;
    }
    if (num[i] >= 2 && i > 0) {
      ans += num[i] * (num[i] - 1) / 2 * num[i - 1];
    }
    if (i > 0)
      num[i] += num[i - 1];
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