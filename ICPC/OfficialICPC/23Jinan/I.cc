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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n / 2; ++i) {
    int l = n, r = n;
    for (int j = 0; j < n; ++j) {
      if (j != a[j] - 1) {
        l = j;
        for (int k = n - 1; k > j; --k) {
          if (a[k] < a[j]) {
            r = k;
            break;
          }
        }
        break;
      }
    }
    if (l == n) {
      break;
    }
    ans.emplace_back(l + 1, r + 1);
    sort(a.begin() + l, a.begin() + r + 1);
  }
  cout << ans.size() << "\n";
  for (auto [l, r] : ans) {
    cout << l << " " << r << "\n";
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