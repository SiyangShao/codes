#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  if (s[0] == 'a') {
    if (s[1] == 'b') {
      cout << s[0] << " ";
      for (int i = 1; i + 1 < n; ++i) {
        cout << s[i];
      }
      cout << " ";
      cout << s[n - 1] << "\n";
    } else {
      // s[1] == 'a'
      cout << s[0] << " " << s[1] << " ";
      for (int i = 2; i < n; ++i) {
        cout << s[i];
      }
      cout << "\n";
    }
  } else {
    if (s[1] == 'a') {
      cout << s[0] << " " << s[1] << " ";
      for (int i = 2; i < n; ++i) {
        cout << s[i];
      }
      cout << "\n";
    } else {
      cout << s[0] << " ";
      for (int i = 1; i + 1 < n; ++i) {
        cout << s[i];
      }
      cout << " ";
      cout << s[n - 1] << "\n";
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
