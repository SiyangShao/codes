#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll ans = 1;
  auto is_fac = [&](ll x) {
    ll f = (ll)sqrt(x);
    return x == f * f;
  };
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll dif = a[j] - a[i];
      // dif = (x+y) * (x-y)
      if (dif % 4 == 2)
        continue;
      for (ll x = 1; x * x < dif; ++x) {
        if (dif % x != 0)
          continue;
        ll cnt = 2;
        ll y = dif / x;
        // y = x + y, x = x - y
        if (x > y)
          swap(x, y);
        ll f_y = (x + y) / 2, f_x = (y - x) / 2;
        // cout << i << " " << j << " " << f_x << " " << f_y << " " << x << " "
        //      << y << "\n";
        if (f_x + f_y == y && f_y - f_x == x && f_y * f_y >= a[j] &&
            f_x * f_x >= a[i]) {
          assert(f_y * f_y - a[j] == f_x * f_x - a[i]);
          for (int k = j + 1; k < n; ++k) {
            if (is_fac(f_y * f_y + a[k] - a[j])) {
              cnt++;
            }
          }
        }
        if (f_x * f_x - a[i] != f_y * f_y - a[j] || f_x * f_x - a[i] < 0)
          cnt = 0;
        ans = max(ans, cnt);
      }
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