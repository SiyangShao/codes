#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll x = 0, y = 0;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == '0') {
      x++;
    } else {
      y++;
    }
  }
  ll ans = x * y;
  if (x == 0 || y == 0) {
    cout << max(x * x, y * y) << "\n";
    return;
  }
  char pre = '2';
  ll cnt = 0;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == pre) {
      cnt++;
    } else {
      ans = max(ans, cnt * cnt);
      pre = s[i];
      cnt = 1;
    }
  }
  ans = max(ans, cnt * cnt);
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