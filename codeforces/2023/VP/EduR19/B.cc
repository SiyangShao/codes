#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  int ans = 0;
  int pos = 1e9, neg = -1e9;
  for (auto i : a) {
    if (i > 0)
      ans += i;
    if (abs(i) % 2 == 1) {
      if (i > 0)
        pos = min(pos, i);
      else
        neg = max(neg, i);
    }
  }
  if (ans % 2 == 1)
    cout << ans << "\n";
  else
    cout << ans - min(pos, -neg) << "\n";
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