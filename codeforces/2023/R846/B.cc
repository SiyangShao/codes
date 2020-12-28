#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  ll ans = 0;
  ll pre = a[0];
  sum -= a[0];
  for (int i = 1; i < n; ++i) {
    ans = max(ans, gcd(sum, pre));
    sum -= a[i];
    pre += a[i];
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