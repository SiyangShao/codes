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
  ll sz = a[0] * 2 - 1;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    if (a[i] <= sz)
      continue;
    ll p = a[i] / sz;
    if (a[i] % sz != 0) {
      p++;
    }
    ans += p - 1;
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