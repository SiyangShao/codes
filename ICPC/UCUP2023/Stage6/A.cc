#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll count(ll x) {
  ll ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
auto solve() {
  ll n;
  cin >> n;
  if (n % 10 != 0) {
    // A take n % 10. B take sth. A take new n % 10.
    cout << "Algosia\n";
    return;
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