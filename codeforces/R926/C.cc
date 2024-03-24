#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
bool cal(ll k, ll x, ll target, ll res) {
  if (res < 0)
    return false;
  ll need = (target + k - 2) / (k - 1);
  if (x == 0) {
    return res >= need;
  }
  // already in base
  // need to earn at least base + 1
  // next should have how much?
  return cal(k, x - 1, need + target, res - need);
}
auto solve() {
  ll k, x, a;
  cin >> k >> x >> a;
  if (cal(k, x, 1, a)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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