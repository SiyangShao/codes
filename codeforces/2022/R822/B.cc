#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  cout << "1\n";
  for (ll i = 2; i <= n; ++i) {
    cout << "1";
    for (ll j = 2; j < i; ++j) {
      cout << " 0";
    }
    cout << " 1\n";
  }
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