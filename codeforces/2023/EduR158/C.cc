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
  for (auto &i : a)
    cin >> i;
  int minElement = *min_element(a.begin(), a.end());
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt = max(cnt, [](int x) {
      int cur = 0;
      while (x) {
        x /= 2;
        cur++;
      }
      return cur;
    }(a[i] - minElement));
  }
  cout << cnt << "\n";
  if (cnt <= n && cnt != 0) {
    for (int i = 0; i < cnt; ++i) {
      cout << minElement << " ";
    }
    cout << "\n";
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