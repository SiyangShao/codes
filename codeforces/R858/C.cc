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
  int m = n * 2;
  vector<ll> a(m);
  ll base = 0;
  for (auto &i : a) {
    cin >> i;
    base += abs(i);
  }
  dbg(base);
  if (n % 2 == 0) {
    ll cnt = 0;
    for (auto &i : a) {
      cnt += abs(i + 1);
    }
    ll mi = LONG_LONG_MAX;
    for (auto &i : a) {
      mi = min(mi, abs(i - n) - abs(i + 1));
    }
    cnt += mi;
    base = min(base, cnt);
  }
  // all same
  // x^n = x * n
  // x^{n-1} = n
  if (n == 1) {
    base = min(base, abs(a[0] - a[1]));
  } else if (n == 2) {
    ll cnt = 0;
    for (auto &i : a) {
      cnt += abs(i - 2);
    }
    base = min(base, cnt);
  }
  cout << base << "\n";
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