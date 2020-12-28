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
  vector<ll> mx(n), mi(n), aft_mx(n), aft_mi(n);
  mx = mi = aft_mx = aft_mi = a;
  for (int i = 1; i < n; ++i) {
    if (mx[i - 1] >= 0) {
      mx[i] += mx[i - 1];
    }
    if (mi[i - 1] <= 0) {
      mi[i] += mi[i - 1];
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (aft_mx[i + 1] >= 0) {
      aft_mx[i] += aft_mx[i + 1];
    }
    if (aft_mi[i + 1] <= 0) {
      aft_mi[i] += aft_mi[i + 1];
    }
  }
  ll dif = 0;
  for (int i = 0; i + 1 < n; ++i) {
    dif = max(dif, abs(mx[i] - aft_mi[i + 1]));
    dif = max(dif, abs(mi[i] - aft_mx[i + 1]));
  }
  cout << dif << "\n";
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