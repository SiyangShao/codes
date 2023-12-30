#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &i : p) {
    cin >> i;
    i--;
  }
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ans = gcd(ans, abs(p[i] - i));
  }
  assert(ans != 0);
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