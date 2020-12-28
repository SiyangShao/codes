#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  reverse(t.begin(), t.end());
  s += t;
  int cnt = 0;
  for (int i = 1; i < n + m; ++i) {
    if (s[i] == s[i - 1])
      cnt++;
  }
  if (cnt <= 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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