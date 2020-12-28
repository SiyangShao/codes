#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll a, b;
  cin >> a >> b;
  ll n, m;
  cin >> n >> m;
  ll ans = min(a, b) * n;
  ll k = n / (m + 1);
  ans = min(ans, k * a * m + (n - k * (m + 1)) * min(a, b));
  ans = min(ans, (k + 1) * a * m);
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
