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
  cout << a[0];
  ll odd = 0, sum = a[0];
  if (sum % 2 == 1)
    odd++;
  for (int i = 1; i < n; ++i) {
    sum += a[i];
    if (a[i] % 2 == 1)
      odd++;
    ll Olya = odd / 3;
    ll res = odd % 3;
    if (res == 1) {
      cout << " " << sum - 1 - Olya;
    } else {
      cout << " " << sum - Olya;
    }
  }
  cout << "\n";
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