#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
#define int ll
auto solve() {
  int n, m;
  cin >> n >> m;
  int l = 1, r = n + m;
  function<bool(int)> check = [&](int x) {
    int N = max(n - x * 3, 0LL);
    int M = max(m - x * 3, 0LL);
    int res = N + M;
    return res <= x;
  };
  int ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << 2 * ans - 1 << "\n";
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}