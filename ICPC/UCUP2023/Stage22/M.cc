#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  int mid = -1;
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
      mid = i;
      break;
    }
  }
  ld ans = 0;
  for (auto i : a) {
    ans += i;
  }
  ans = ans / (ld)n;
  // all left
  ld sum = 0, cnt = 0;
  for (int i = 0; i <= mid; ++i) {
    sum += a[i];
  }
  for (int i = mid + 1; i < n; ++i) {
    sum += a[i];
    cnt = sum / (i + 1);
    ans = max(ans, cnt);
  }
  sum = 0, cnt = 0;
  int num = 0;
  for (int i = n - 1; i >= mid; --i) {
    sum += a[i];
    num++;
  }
  for (int i = mid - 1; i >= 0; --i) {
    sum += a[i];
    num++;
    cnt = sum / ld(num);
    ans = max(ans, cnt);
  }
  cout << fixed << setprecision(16) << ans << "\n";
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