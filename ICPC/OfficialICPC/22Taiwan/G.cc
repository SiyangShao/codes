#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  for (int len = n / 2; len >= 1; --len) {
    for (int i = 0; i + len + len < n; ++i) {
      auto str = s.substr(i, len);
      auto pos = s.find(str, i + len);
      if (pos != string::npos) {
        cout << str << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
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