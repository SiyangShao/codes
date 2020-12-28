#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  if (s == "()") {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  bool flag = false;
  for (int i = 1; i < (int)s.length(); ++i) {
    if (s[i] == s[i - 1]) {
      flag = true;
      break;
    }
  }
  if (flag) {
    for (int i = 0; i < (int)s.length(); ++i) {
      cout << "()";
    }
    cout << "\n";
  } else {
    for (int i = 0; i < (int)s.length(); ++i) {
      cout << "(";
    }
    for (int i = 0; i < (int)s.length(); ++i) {
      cout << ")";
    }
    cout << "\n";
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