#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto cal(ll x) {
  // number of i, which i*i <= x
  ll bs = sqrtl(x);
  // number of i, which (i-1)*i <= x
  ll cnt = sqrtl(x);
  // cnt * cnt <= x, so cnt * (cnt-1) <= x
  if (cnt * (cnt + 1) <= x) {
    cnt++;
  }
  // cnt = cnt + 1;
  // cnt * cnt >=x
  bs += cnt;
  cnt = sqrtl(x);
  // number of i which (i-2) * i <= x;
  if ((cnt + 1) * (cnt - 1) <= x) {
    cnt++;
  }
  if ((cnt + 1) * (cnt - 1) <= x) {
    cnt++;
  }
  bs += cnt;
  return bs;
}
auto init() {
  for (ll i = 1; i <= 100000000; ++i) {
    ll s = sqrtl(i);
    if (i % s == 0) {
      assert(cal(i) - cal(i - 1) == 1);
    } else {
      assert(cal(i) - cal(i - 1) == 0);
    }
  }
}
auto solve() {
  ll l, r;
  cin >> l >> r;
  l--;
  cout << cal(r) - cal(l) << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  // init();
  while (_--) {
    solve();
  }
}