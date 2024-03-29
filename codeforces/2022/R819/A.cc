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
  ll ans = a[n - 1] - a[0];
  if (n == 1) {
    cout << ans << "\n";
    return;
  }
  for (ll i = 0; i < n; ++i) {
    ans = max(ans, a[(i + n - 1) % n] - a[i]);
  }
  ll mi = *min_element(a.begin(), a.begin() + n - 1);
  ans = max(ans, a[n - 1] - mi);
  ll mx = *max_element(a.begin() + 1, a.end());
  ans = max(ans, mx - a[0]);
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