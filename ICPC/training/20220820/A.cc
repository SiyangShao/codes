#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  ll cnt = 0;
  for (ll i = 1; i <= n; ++i) {
    cnt += i * i;
  }
  cout << cnt * m << "\n";
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