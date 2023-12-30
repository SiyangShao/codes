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
  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  ll op = 0, x = 0;
  while (l < r) {
    assert(a[r] >= a[l] and a[r] > x);
    ll dif = min(a[r] - x, a[l]);
    op += dif;
    x += dif;
    if (x == a[r]) {
      r--;
      x = 0;
      op++;
    }
    if (dif == a[l]) {
      l++;
    } else {
      a[l] -= dif;
    }
  }
  // cout << x << " " << a[l] << "\n";
  if (l == r) {
    ll res = a[l];
    // cur: x
    ll chi = (res - x) / 2;
    op += chi;
    x += chi;
    assert(res >= x + chi);
    res -= chi;
    if (res and x!=0) {
      op++;
      res -= x;
    }
    op += res;
    // cout << res << " ";
    // op += res;
    // x += (res - x) / 2;
    // res -= x;
    // op++;
    // op += res;
  }
  cout << op << "\n";
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