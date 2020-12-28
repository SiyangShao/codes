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
  for (ll i = 1; i + 1 < n; ++i) {
    ll l = a[i - 1], mid = a[i], r = a[i + 1];
    ll x = lcm(l, mid), y = lcm(mid, r);
    if (gcd(x, y) != mid) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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