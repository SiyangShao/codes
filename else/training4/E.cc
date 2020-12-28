#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto check(vector<ll> &b) {
  auto n = b.size();
  for (size_t i = 0; i + 5 < n; i++) {
    for (size_t x = 1; x < 6; ++x) {
      for (size_t y = x + 1; y < 6; ++y) {
        if (b[i] + b[i + x] > b[i + y]) {
          vector<ll> c(3);
          int t = 0;
          for (size_t k = 1; k < 6; ++k) {
            if (k == x || k == y)
              continue;
            c[t++] = b[i + k];
          }
          if (c[0] + c[1] > c[2]) {
            return true;
          }
        }
      }
    }
  }
  int num = 0;
  for (size_t i = 0; i + 2 < n; ++i) {
    if (b[i] + b[i + 1] > b[i + 2]) {
      i += 2;
      num++;
    }
  }
  return num >= 2;
}
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    if (r - l + 1 >= 100) {
      cout << "YES\n";
      continue;
    }
    vector<ll> b(r - l + 1);
    for (int i = 0; i < r - l + 1; i++) {
      b[i] = a[i + l];
    }
    ranges::sort(b);
    if (check(b)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
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