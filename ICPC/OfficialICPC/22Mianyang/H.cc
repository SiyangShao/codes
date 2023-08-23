#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int k;
  cin >> k;
  cout << k * 2 << "\n";
  for (int i = 1; i <= k * 2; ++i) {
    cout << i << " " << i << "\n";
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