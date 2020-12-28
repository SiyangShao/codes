// 我相信我相信的一切
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
  vector<ll> b(n);
  for (auto &i : b)
    cin >> i;
  ll ans = 1;
  for (auto i : b) {
    ans *= i;
  }
  if (2023 % ans == 0) {
    cout << "YES\n";
    cout << 2023 / ans;
    for (int i = 1; i < k; ++i) {
      cout << " 1";
    }
    cout << "\n";
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