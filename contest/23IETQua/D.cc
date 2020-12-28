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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b;
  for (auto &i : a) {
    cin >> i;
    if (i % k == 0) {
      b.emplace_back(i);
    }
  }
  int cur = 0;
  for (auto i : b) {
    cur = gcd(i, cur);
  }
  if (cur == k) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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