#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  ll sum = 0;
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n > 3) {
    cout << n * (*max_element(a.begin(), a.end())) << "\n";
  } else if (n == 1) {
    cout << a[0] << "\n";
  } else if (n == 2) {
    cout << max(a[0] + a[1], 2 * abs(a[1] - a[0])) << "\n";
  } else {
    if (a[0] > a[2])
      swap(a[0], a[2]);
    cout << max({a[0] + a[1] + a[2], a[2] * 3, (a[1] - a[0]) * 3}) << "\n";
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