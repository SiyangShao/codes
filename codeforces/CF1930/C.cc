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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  for (int i = 0; i < n; ++i) {
    a[i] += i + 1;
  }
  ranges::sort(a, greater<>());
  for (int i = 1; i < n; ++i) {
    a[i] = min(a[i], a[i - 1] - 1);
  }
  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n";
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