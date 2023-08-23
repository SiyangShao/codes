#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  ll n = s.length();
  ll num = 0, pos = n - 1;

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      num += pos - i;
      pos--;
    }
  }
  if (num % 3 == 0) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
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