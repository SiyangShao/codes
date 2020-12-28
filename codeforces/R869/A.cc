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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> num(n + 1, 0);
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i - 1] >= a[i] && a[i] >= a[i + 1])
      num[i + 1] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    num[i] += num[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    ll len = num[r] - num[l - 1];
    if (num[l] != num[l - 1])
      len--;
    if (l != r && num[r] != num[r - 1])
      len--;
    cout << r - l + 1 - len << "\n";
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