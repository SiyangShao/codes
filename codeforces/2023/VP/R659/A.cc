#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  set<pair<char, char>> st;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i])
      continue;
    if (a[i] > b[i]) {
      cout << "-1\n";
      return;
    }
    st.emplace(a[i], b[i]);
  }
  map<char, char> mp;
  int ans = 0;
  for (auto [l, r] : st) {
    if (!mp.contains(l)) {
      mp[l] = r;
      ans++;
    } else {
      assert(mp[l] < r);
      st.emplace(mp[l], r);
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