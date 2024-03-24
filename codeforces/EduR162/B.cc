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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> x(n);
  for (auto &i : x)
    cin >> i;
  vector<ll> val(n + 1);
  for (int i = 0; i < n; ++i) {
    val[abs(x[i])] += a[i];
  }
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += k;
    if (sum >= val[i]) {
      sum -= val[i];
    } else {
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