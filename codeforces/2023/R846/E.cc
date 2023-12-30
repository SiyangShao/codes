#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll l, r;
  cin >> l >> r;
  l--;
  if (r >= l * 3) {
    cout << r / 2 << "\n";
    return;
  }
  ll ans = 0;
  for (ll i = 1, j; i <= r; i = j + 1) {
    j = r / (r / i);
    if (i <= l)
      j = min(j, l / (l / i));
    if (r / i >= l / i + 2)
      ans += j - i + 1;
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