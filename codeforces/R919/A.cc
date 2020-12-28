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
  set<ll> notEqual;
  ll l = 0, r = 1e9;
  while (n--) {
    ll a, x;
    cin >> a >> x;
    if (a == 1) {
      l = max(l, x);
    } else if (a == 2) {
      r = min(r, x);
    } else {
      notEqual.emplace(x);
    }
  }
  ll num = r - l + 1;
  for (auto i : notEqual) {
    if (i >= l && i <= r) {
      num--;
    }
  }
  num = max(num, 0LL);
  cout << num << "\n";
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