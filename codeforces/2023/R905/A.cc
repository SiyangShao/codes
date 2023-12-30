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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  function<bool(int, vector<int> &)> check = [&](int del, vector<int> &tmp_a) {
    for (int i = 0; i + del < n; ++i) {
      if (tmp_a[i] >= b[i + del]) {
        return false;
      }
    }
    return true;
  };
  function<int(int)> solve = [&](int x) {
    a[0] = x;
    auto tmp_a = a;
    ranges::sort(tmp_a);
    int l = 0, r = n;
    int ans = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid, tmp_a)) {
        r = mid - 1;
        ans = min(ans, mid);
      } else {
        l = mid + 1;
      }
    }
    return ans;
  };
  int x = solve(1), y = solve(m);
  assert(y - x == 1 || y - x == 0);
  if (y == x) {
    cout << (ll)x * m << "\n";
  } else {
    int l = 1, r = m;
    int ans = l;
    while (l <= r) {
      int mid = (l + r) / 2;
      int z = solve(mid);
      if (z == x) {
        l = mid + 1;
        ans = max(ans, mid);
      } else {
        r = mid - 1;
      }
    }
    cout << (ll)x * ans + (ll)y * (m - ans) << "\n";
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