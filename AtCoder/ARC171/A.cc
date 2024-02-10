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
  ll n, a, b;
  cin >> n >> a >> b;
  if (a > n) {
    cout << "No\n";
    return;
  }
  ll res = n - a;
  ll can;
  if (a >= n / 2) {
    can = res * res;
  } else {
    ll tmp = (n - a * 2 + 1) / 2;
    can = res * a + res * tmp;
  }
  if (can >= b) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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