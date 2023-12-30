#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s, t;
  cin >> s >> t;
  s = "_" + s;
  int n = (int)s.length();
  vector<int> mp(26, n);
  for (int i = 1; i < n; ++i) {
    mp[s[i] - 'a'] = min(mp[s[i] - 'a'], i);
  }
  for (auto j : t) {
    if (mp[j - 'a'] == n) {
      cout << "-1\n";
      return;
    }
  }
  vector<array<int, 26>> nxt(n);
  for (auto &i : nxt) {
    fill(i.begin(), i.end(), n);
  }
  for (int i = n - 2; i >= 0; --i) {
    nxt[i][s[i + 1] - 'a'] = i + 1;
    for (int j = 0; j < 26; ++j) {
      nxt[i][j] = min(nxt[i][j], nxt[i + 1][j]);
    }
  }
  int cur = 0, ans = 1;
  for (auto i : t) {
    if (nxt[cur][i - 'a'] == n) {
      cur = nxt[0][i - 'a'];
      ans++;
    } else {
      cur = nxt[cur][i - 'a'];
    }
  }
  cout << ans << "\n";
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