#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<>());
  int t = m / (k + 1);
  ll ans = a[0] * m;
  ans += t * a[1];
  ans -= t * a[0];
  cout << ans << "\n";
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