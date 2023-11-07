#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll f(ll x) {
  ll y = 0;
  while ((1LL << y) <= x) {
    y++;
  }
  // cout << x << " " << y - 1 << "\n";
  return y - 1;
}
ll g(ll x) {
  ll F = f(x);
  ll cur = 1;
  ll y = 0;
  while (cur <= x) {
    cur *= F;
    y++;
  }
  // cout << x << " " << y - 1 << "\n";
  return y - 1;
}
ll sum(ll x) {
  ll ans = 0;
  for (ll i = 4; i <= x; ++i) {
    ans += g(i);
  }
  return ans;
}
auto solve() {
  for (int i = 0; i <= 10; ++i) {
    cout << sum(i) << "\n";
  }
}
auto main() -> int {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}