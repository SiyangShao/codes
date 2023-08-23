#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  array<ll, 4> a;
  for (auto &i : a)
    cin >> i;
  if (a[0] == 0) {
    cout << 1 << "\n";
    return;
  }
  ll ans = a[0];
  ll x = ans, y = ans;
  ans += min(a[1], a[2]) * 2;
  ll cur = min(a[1], a[2]);
  a[1] -= cur;
  a[2] -= cur;
  assert(a[1] == 0 || a[2] == 0);
  assert(x == y);
  if (a[3] <= x) {
    x -= a[3];
    y -= a[3];
    ans += a[3];
    assert(x == y);
    cout << ans + min(x + 1, max(a[1], a[2])) << "\n";
  } else {
    cout << ans + x + 1 << "\n";
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