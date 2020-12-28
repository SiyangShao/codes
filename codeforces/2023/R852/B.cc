#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll x, y;
  cin >> x >> y;
  cout << 2 * (x - y) << "\n";
  for (ll i = x; i >= y; --i) {
    cout << i << " ";
  }
  for (ll i = y + 1; i < x; ++i) {
    cout << i << " ";
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
