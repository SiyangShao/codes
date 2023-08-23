#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  if (x < y) {
    swap(x, y);
  }
  // x >= y
  if (y > 0 || x == 0) {
    cout << "-1\n";
    return;
  }
  if ((n - 1) % x != 0) {
    cout << "-1\n";
    return;
  }
  for (ll i = 0; i < x; ++i) {
    cout << 1 << " ";
  }
  ll res = (n - 1) / x;
  res--;
  ll beg = x + 2;
  for (ll i = 0; i < res; ++i) {
    for (ll j = 0; j < x; ++j) {
      cout << beg + i * x << " ";
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