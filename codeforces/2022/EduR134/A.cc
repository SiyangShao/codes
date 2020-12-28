#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s1, s2;
  cin >> s1 >> s2;
  map<char, ll> mp;
  mp.clear();
  mp[s1[0]]++, mp[s2[0]]++, mp[s1[1]]++, mp[s2[1]]++;
  ll mx = 0, rev = -1;
  for (auto &[x, cnt] : mp) {
    if (mx <= cnt) {
      rev = max(rev, mx);
      mx = cnt;
    }
  }
  if (mx == 4) {
    cout << "0\n";
  } else if (mx == 3) {
    cout << "1\n";
  } else if (mx == 1) {
    cout << "3\n";
  } else {
    if (rev == 2) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
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