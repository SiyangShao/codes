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
  for (int i = n - 1; i > 1; --i) {
    ll d = max(0LL, a[i - 1] - a[i]);
    a[i - 1] -= d;
    a[i - 2] -= d;
  }
  dbg(a);
  for (int i = 0; i + 2 < n; ++i) {
    ll d = max(0LL, a[i] - a[i + 1]);
    a[i + 1] += d;
    a[i + 2] += d;
  }
  dbg(a);
  cout << (ranges::is_sorted(a) ? "YES" : "NO") << "\n";
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