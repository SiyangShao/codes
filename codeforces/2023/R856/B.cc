#include <bits/stdc++.h>
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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : a) {
    if (i == 1)
      i++;
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i + 1] % a[i] == 0) {
      a[i + 1]++;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i + 1 == n];
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