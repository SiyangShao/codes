#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll ans = 0;
  for (ll i = 0; i < k; ++i) {
    ll tmp = 0;
    for (ll j = i; j < n; j += k) {
      tmp = max(tmp, a[j]);
    }
    ans += tmp;
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