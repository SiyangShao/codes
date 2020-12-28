#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  reverse(s2.begin(), s2.end());
  map<pair<char, char>, ll> mp;
  for (ll i = 0; i < n; ++i) {
    if (s1[i] < s2[i]) {
      swap(s1[i], s2[i]);
    }
    mp[{s1[i], s2[i]}]++;
  }
  ll ans = 0;
  for (auto &[u, v] : mp) {
    if (v % 2 == 1) {
      if (n % 2 == 1 && ans == 0 && u.first == u.second) {
        ans = 1;
        continue;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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