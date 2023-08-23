#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  ll one = 0;
  for (auto &i : s) {
    if (i == '1') {
      one++;
    }
  }
  ll zero = s.length() - one;
  if (zero > one) {
    for (ll i = 0; i < s.length(); ++i) {
      cout << "1";
    }
  } else if (zero < one) {
    for (ll i = 0; i < s.length(); ++i) {
      cout << "0";
    }
  } else {
    if (s[0] == '0') {
      cout << "1";
      for (ll i = 1; i < s.length(); ++i) {
        cout << "0";
      }
    } else {
      cout << "0";
      for (ll i = 1; i < s.length(); ++i) {
        cout << "1";
      }
    }
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