#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  ll bs = 100, cnt = 100;
  for (ll i = 0; i < n; ++i) {
    ll tmp;
    cin >> tmp;
    bs += tmp;
    cnt = max(cnt, bs);
  }
  cout << cnt << "\n";
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