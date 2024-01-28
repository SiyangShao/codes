#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9;
auto solve() {
  ll n;
  cin >> n;
  ll ans = 1;
  for (ll i = 1; i <= n; ++i) {
    ans *= i;
    dbg(ans);
    if (ans % MOD == 0) {
      dbg(i);
      break;
    }
  }
  string ansstr = to_string(ans);
  string cur = "";
  for (int i = 0; i < 9; ++i) {
    if (i >= ansstr.size()) {
      break;
    }
    cur += ansstr[ansstr.size() - 1 - i];
  }
  while (cur.size() != 9) {
    cur += '0';
  }
  reverse(cur.begin(), cur.end());
  cout << cur << "\n";
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