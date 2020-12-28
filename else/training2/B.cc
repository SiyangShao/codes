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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  string s;
  cin >> s;
  char pre = '.';
  vector<vector<ll>> cal;
  vector<ll> tmp;
  for (int i = 0; i < n; ++i) {
    if (s[i] == pre) {
      tmp.emplace_back(a[i]);
    } else {
      pre = s[i];
      if (!tmp.empty()) {
        cal.emplace_back(tmp);
      }
      tmp.clear();
      tmp.emplace_back(a[i]);
    }
  }
  if (!tmp.empty()) {
    cal.emplace_back(tmp);
  }
  ll ans = 0;
  for (auto &vec : cal) {
    sort(vec.begin(), vec.end(), greater<>());
    for (int i = 0; i < (int)vec.size() && i < k; ++i) {
      ans += vec[i];
    }
  }
  cout << ans << "\n";
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