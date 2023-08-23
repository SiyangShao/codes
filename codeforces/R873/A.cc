#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  ll ans = (1 + n) * n / 2;
  if (ans % n != 0) {
    ll first = n - (ans % n);
    ans += first;
    cout << first + 1;
  } else {
    cout << 1;
  }
  for (ll i = 2; i <= n; ++i) {
    cout << " " << i;
  }
  cout << "\n";
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