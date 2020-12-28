#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  if (n % 2 == 0) {
    for (ll i = n - 2; i >= 1; --i) {
      cout << i << " ";
    }
    cout << n - 1 << " " << n << "\n";
  } else {
    cout << 1 << " ";
    for (ll i = n - 2; i > 1; --i) {
      cout << i << " ";
    }
    cout << n - 1 << " " << n << "\n";
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