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
  ll n, c, p, q;
  cin >> n >> c >> p >> q;
  ll g = gcd(p, q);
  p /= g, q /= g;
  auto check = [&](ll cnt, ll len) {
    // cnt / len >= p / q
    // cnt * q >= p * len
    return cnt * q >= p * len;
  };
  string s;
  cin >> s;
  ll level = 0, pre = -1;
  for (ll i = 0; i < n; ++i) {
    if (i - pre < c)
      continue;
    ll cnt = 0;
    for (ll j = i; j > i - c; --j) {
      if (s[j] == 'Y')
        cnt++;
    }
    if (check(cnt, c)) {
      level++;
      pre = i;
      continue;
    }
    bool flag = false;
    for (ll j = i - c; j > i - c * 2 && j > pre; --j) {
      if (s[j] == 'Y')
        cnt++;
      if (check(cnt, i - j + 1)) {
        flag = true;
        break;
      }
    }
    if (flag) {
      level++;
      pre = i;
    }
  }
  cout << level << "\n";
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