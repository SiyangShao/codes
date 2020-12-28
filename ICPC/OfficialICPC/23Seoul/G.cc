#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using i128 = __int128;
auto solve() {
  int n, k, m, f;
  cin >> n >> k >> m >> f;
  vector<i128> msk(n + 10);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < m; ++j) {
      int val;
      cin >> val;
      msk[val] |= (i128)1 << i;
    }
  }
  map<i128, int> mp;
  for (int i = 1; i <= n; ++i) {
    if (mp.find(msk[i]) == mp.end()) {
      mp[msk[i]] = i;
    } else {
      mp[msk[i]] = 0;
    }
  }
  for (int i = 0; i < f; ++i) {
    string s;
    cin >> s;
    i128 cur = 0;
    for (int j = 0; j < k; ++j) {
      if (s[j] == 'Y') {
        cur |= (i128)1 << j;
      }
    }
    cout << mp[cur] << '\n';
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