#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s, t;
  cin >> s >> t;
  if (s.find(t) != string::npos) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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