#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll x;
  cin >> x;
  while (x % 10 == 0 && x != 0) {
    x /= 10;
  }
  string s = to_string(x);
  auto b = s;
  reverse(b.begin(), b.end());
  if (b == s) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
