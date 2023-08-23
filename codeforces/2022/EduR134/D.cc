#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  auto check = [&](ll x) {
    vector<ll> c(n), d(n);
    for (ll i = 0; i < n; ++i) {
      c[i] = a[i] & x;
      d[i] = (~b[i]) & x;
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    return c == d;
  };
  ll ans = 0;
  for (ll d = 30; d >= 0; --d) {
    if (check(ans | (1LL << d))) {
      ans |= 1LL << d;
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