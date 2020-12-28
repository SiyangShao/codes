#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string output = "";
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a' && i - 1 >= 0 && s[i - 1] == 'n') {
      output += "ya";
    } else {
      output += s[i];
    }
  }
  cout << output << "\n";
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