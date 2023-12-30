#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 2e5;
using bst = bitset<N>;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  bst base;
  base[1] = true;
  ll ans = 0, sum = 0;
  for (int i = 0; i < n * 2; ++i) {
    base |= base << a[i];
    sum += a[i];
    if (base[i + 1]) {
      ans = max(ans, sum - i);
    }
    base[i + 1] = false;
  }
  cout << ans << "\n";
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