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
  sort(a.begin(), a.end());
  ll ans = 3e9 + 7;
  for (ll i = 1; i + 1 < n; ++i) {
    ll L = a[i] - a[i - 1];
    ll R = a[i + 1] - a[i];
    ans = min(ans, L + R);
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