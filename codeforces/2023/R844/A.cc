#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
auto solve() {
  ll w, d, h;
  cin >> w >> d >> h;
  ll a, b, f, g;
  cin >> a >> b >> f >> g;
  ll ans = d - b + abs(f - a) + abs(d - g);
  ans = min(ans, b + abs(f - a) + g);
  ans = min(ans, a + f + abs(g - b));
  ans = min(ans, (w - a) + (w - f) + abs(g - b));
  cout << ans + h << "\n";
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