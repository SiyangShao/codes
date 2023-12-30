转运#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (*ranges::max_element(a) == *ranges::min_element(a)) {
    cout << "0\n";
    return;
  }
  int flag = 0;
  for (auto i : a) {
    if (i == k) {
      cout << "-1\n";
      return;
    }
    if (i > k) {
      if (flag == -1) {
        cout << "-1\n";
        return;
      }
      flag = 1;
    } else if (i < k) {
      if (flag == 1) {
        cout << "-1\n";
        return;
      }
      flag = -1;
    }
  }
  ll gcdVal = 0;
  for (auto i : a) {
    gcdVal = gcd(gcdVal, abs(i - k));
  }
  ll ans = 0;
  for (auto i : a) {
    ans += abs(i - k) / gcdVal - 1;
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