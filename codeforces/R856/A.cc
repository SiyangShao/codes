#include <bits/stdc++.h>
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
  vector<string> mp(n * 2 - 2);
  for (auto &i : mp)
    cin >> i;
  vector<vector<string>> cnt(n);
  for (int i = 0; i < n * 2 - 2; ++i) {
    cnt[mp[i].length()].emplace_back(mp[i]);
  }
  for (auto &i : cnt) {
    if (i.empty())
      continue;
    assert(i.size() == 2);
    auto l = i[0], r = i[1];
    reverse(r.begin(), r.end());
    if (l != r) {
      cout << "NO\n";
      return;
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