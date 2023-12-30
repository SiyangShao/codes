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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> prefix_sum(n + 1, 0);
  vector<int> up(n+1,0);
  iota(up.begin(),up.end(),0);
  int len = 1, ans = 0;
  for (int i = 1; i < n; ++i) {
    prefix_sum[i] = ans + min(len, 2);
    if (a[i] <= a[i - 1]) {
      up[i + 1] = up[i];
      len++;
    } else {
      ans += min(len, 2);
      len = 1;
    }
  }
  prefix_sum[n] = ans + min(len, 2);
  dbg(prefix_sum);
  dbg(up);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l = up[l]-1;
    cout << prefix_sum[r] - prefix_sum[l] << "\n";
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