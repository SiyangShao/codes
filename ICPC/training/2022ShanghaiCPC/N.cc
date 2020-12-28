#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a << "=" << b << "\n";
    return;
  }
  for (int i = 0; i < min(a.length(), b.length()); ++i) {
    if (a[i] == b[i]) {
      continue;
    }
    if (a[i] < b[i]) {
      cout << a << "<" << b << "\n";
      return;
    } else {
      cout << a << ">" << b << "\n";
      return;
    }
  }
  if (a.length() > b.length()) {
    cout << a << ">" << b << "\n";
  } else {
    cout << a << "<" << b << "\n";
  }
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