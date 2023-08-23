#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll cur = s[0] - '0';
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') {
      cout << "-";
    } else {
      if (cur >= 0) {
        cout << "-";
        cur--;
      } else {
        cout << "+";
        cur++;
      }
    }
  }
  cout << "\n";
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