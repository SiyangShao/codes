#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string L, R;
  cin >> L >> R;
  while (L.length() < R.length()) {
    L.insert(0, "0");
  }
  int n = (int)L.length();
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (L[i] == R[i])
      continue;
    else {
      ans = (R[i] - L[i]) + 9 * (n - i - 1);
      break;
    }
  }
  cout << ans << "\n";
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