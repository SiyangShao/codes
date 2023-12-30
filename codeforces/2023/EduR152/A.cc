#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int b, c, h;
  cin >> b >> c >> h;
  int lev = b - 1;
  if (c + h >= lev) {
    cout << b + lev << "\n";
  } else {
    cout << c + h + c + h + 1 << "\n";
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