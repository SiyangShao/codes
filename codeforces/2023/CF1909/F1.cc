#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
ll C(ll x, ll y) {
  assert(y == 0 || y == 1 || y == 2);
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  return (y * (y - 1) / 2) % MOD;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  if (a.back() != n) {
    cout << "0\n";
    return;
  }
  int pre = 0;
  ll res = 0, ans = 1;
  for (auto i : a) {
    int dif = i - pre;
    if (dif < 0 || dif > 2) {
      cout << "0\n";
      return;
    }
    ll cur = 1;
    if (dif == 1) {
      cur = res * 2 + 1;
    } else if (dif == 2) {
      cur = res * res % MOD;
    }
    res = res + 1 - dif;
    ans = (ans * cur) % MOD;
    pre = i;
  }
  cout << ans << "\n";
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