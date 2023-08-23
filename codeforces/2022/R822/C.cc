#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string t;
  cin >> t;
  ll ans = 0;
  t = "_" + t;
  for (ll i = 1; i <= n; ++i) {
    for (ll k = 1; i * k <= n; k++) {
      if (t[i * k] == '1') {
        break;
      }
      if (t[i * k] == '_') {
        continue;
      }
      ans += i;
      t[i * k] = '_';
    }
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