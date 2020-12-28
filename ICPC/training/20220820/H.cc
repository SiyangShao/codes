#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    cout << "1\n";
  } else if (n == 2) {
    cout << "2\n";
    cout << "1 1\n";
  } else {
    cout << (n - 2) * 2 << "\n";
    for (ll i = 2; i <= n - 1; ++i) {
      cout << i << " ";
    }
    for (ll i = n - 1; i >= 2; --i) {
      cout << i << " ";
    }
    cout << "\n";
  }
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