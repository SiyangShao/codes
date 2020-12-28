#include <bits/stdc++.h>
using namespace std;
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  string a = s, b = s, c = s;
  map<string, int> mp;
  for (int i = 0; i < n; ++i) {
    int x = i;
    string cur = "aaa";
    int id = 0;
    while (x) {
      cur[id] += x % 26;
      x /= 26;
      id++;
    }
    a[i] = cur[0], b[i] = cur[1], c[i] = cur[2];
    mp[cur] = i;
  }
  string x, y, z;
  cout << "? " << a << endl;
  cin >> x;
  cout << "? " << b << endl;
  cin >> y;
  cout << "? " << c << endl;
  cin >> z;
  string ans = s;
  for (int i = 0; i < n; ++i) {
    string cur = "abc";
    cur[0] = x[i], cur[1] = y[i], cur[2] = z[i];
    ans[mp[cur]] = s[i];
  }
  cout << "! " << ans << endl;
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