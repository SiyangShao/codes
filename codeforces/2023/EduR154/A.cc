#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  for (int i = 0; i < 10; ++i) {
    if (s[i] == '1') {
      cout << "13\n";
      return;
    } else if (s[i] == '3') {
      cout << "31\n";
      return;
    }
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