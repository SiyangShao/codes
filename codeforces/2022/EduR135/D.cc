#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  ll l = 0, r = s.length() - 1;
  while (l <= r) {
    if (s[l] == s[r]) {
      l++, r--;
    } else {
      break;
    }
  }
  if (r > l) {
    if ((r - l + 1) % 2 != 0) {
      cout << "Alice\n";
      return;
    }
    for (ll i = l; i <= r; i += 2) {
      if (s[i] != s[i + 1]) {
        cout << "Alice\n";
        return;
      }
    }
  }
  cout << "Draw\n";
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