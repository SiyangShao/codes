#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  ll ans = 0;
  for (auto i : s) {
    if (i == 'w')
      ans++;
    ans++;
  }
  cout << ans << "\n";
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