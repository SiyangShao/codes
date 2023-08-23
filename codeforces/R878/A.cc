#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char beg;
  bool flag = true;
  for (auto i : s) {
    if (flag) {
      cout << i;
      beg = i;
      flag = false;
    } else if (beg == i) {
      flag = true;
    } else {
      continue;
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