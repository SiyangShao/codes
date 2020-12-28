#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto output(ll l, ll r, ll len) {
  if (l == r) {
    for (ll i = 1; i <= len / 2; ++i) {
      cout << i << " " << l << "\n";
      cout << (len - i + 1) << " " << l << "\n";
    }
    if (len % 2 == 1) {
      ll mid = (len + 1) / 2;
      cout << mid << " " << l << "\n";
    }
    return;
  }
  for (ll i = 1; i <= len; ++i) {
    cout << i << " " << l << "\n";
    cout << (len - i + 1) << " " << r << "\n";
  }
}
auto solve() {
  ll n, m;
  cin >> m >> n;
  for (ll l = 1, r = n; l <= r; l++, r--) {
    output(l, r, m);
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}