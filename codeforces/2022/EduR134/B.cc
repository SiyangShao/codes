#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, sx, sy, d;
  cin >> n >> m >> sx >> sy >> d;
  bool flag1 = sx - d <= 1, flag2 = sx + d >= n;
  bool flag3 = sy - d <= 1, flag4 = sy + d >= m;
  if ((flag1 && flag2) || (flag3 && flag4) || (flag1 && flag3) ||
      (flag2 && flag4)) {
    cout << "-1\n";
  } else {
    cout << (n - 1) + (m - 1) << "\n";
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