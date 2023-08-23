#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  ll tmp = n, ans = 0;
  while (tmp) {
    ll cnt = tmp % 10;
    if (cnt != 0 && n % cnt == 0) {
      ans++;
    }
    tmp /= 10;
  }
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