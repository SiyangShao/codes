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
  ll c;
  cin >> c;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin() + 1, a.end(), [=](auto x, auto y) {
    return x.first - c * x.second > y.first - c * y.second;
  });
  ll sum = a[0].first;
  for (int i = 1; i < n; ++i) {
    sum += a[i].first;
    if (sum < c * a[i].second) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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