#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  for (int i = 1; i + 1 < n; ++i) {
    if (k > 0 && gcd(a[i], a[i - 1]) == 1 && gcd(a[i], a[i + 1]) == 1 &&
        a[i - 1] != 1 && a[i + 1] != 1) {
      a[i] = 0;
      k--;
    }
  }
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      int j = i;
      while (j + 1 < n && a[j + 1] == 1)
        j++;
      if (i != 0 && j != n - 1)
        v.emplace_back(j - i + 1, i, j);
      else
        v.emplace_back(inf, i, j);
      i = j;
    }
  }
  ranges::sort(v);
  for (auto [len, l, r] : v) {
    if (k >= len) {
      k -= len;
      for (int i = l; i <= r; ++i) {
        a[i] = 0;
      }
    } else {
      if (l == 0) {
        for (int i = r; i >= l && k > 0; i--) {
          a[i] = 0;
          k--;
        }
      } else {
        for (int i = l; i <= r && k > 0; ++i) {
          a[i] = 0;
          k--;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (k > 0 && ((i > 0 && gcd(a[i], a[i - 1]) == 1) ||
                  (i + 1 < n && gcd(a[i], a[i + 1]) == 1))) {
      a[i] = 0;
      k--;
    }
  }
  int ans = 0;
  dbg(a);
  for (int i = 1; i < n; ++i) {
    ans += gcd(a[i], a[i - 1]) == 1 ? 1 : 0;
  }
  cout << ans << "\n";
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