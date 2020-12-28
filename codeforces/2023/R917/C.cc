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
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> a(n), b(k);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  ll ans = 0;
  for (int i = 0; i <= n * 2; ++i) {
    if (i >= d)
      break;
    int res = (d - (i + 1));
    ll base = res / 2;
    for (int j = 0; j < n; ++j) {
      if (a[j] == j + 1) {
        base++;
      }
    }
    ans = max(ans, base);
    for (int j = 0; j < b[i % k]; ++j) {
      a[j]++;
    }
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