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
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  reverse(a.begin(), a.end());
  ll pre = a[0];
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > pre) {
      ll lef = 1, rig = a[i] / pre + 1;
      ll sum = a[i] / pre + 1;
      while (lef <= rig) {
        ll mid = (lef + rig) / 2;
        if ((a[i] + mid - 1) / mid <= pre) {
          rig = mid - 1;
          sum = min(sum, mid);
        } else {
          lef = mid + 1;
        }
      }
      pre = a[i] / sum;
      ans += sum - 1;
    } else {
      pre = a[i];
    }
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