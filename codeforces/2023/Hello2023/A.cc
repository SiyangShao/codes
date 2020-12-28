#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool has_R = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      has_R = true;
    } else {
      if (has_R) {
        cout << "0\n";
        return;
      }
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == 'L' && s[i + 1] == 'R') {
      cout << i + 1 << " "
           << "\n";
      return;
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
