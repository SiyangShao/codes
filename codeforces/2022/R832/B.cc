#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  cout << n / 2 + (n % 2 == 1 ? 1 : 0) << "\n";
  for (ll i = 1, j = n; i <= j; i++, j--) {
    cout << i * 3 - 2 << " " << j * 3 - 1 << "\n";
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