#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int x, k;
  cin >> x >> k;
  if (x % k != 0) {
    cout << "1\n" << x << "\n";
  } else {
    cout << "2\n" << x + 1 << " " << -1 << "\n";
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