#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 3; i < (int)s.length(); ++i) {
    if (s[i] == 'a' && s[i - 1] == 'i' && s[i - 2] == 'n' && s[i - 3] == 'a') {
      s[i] = 'z';
      ans++;
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