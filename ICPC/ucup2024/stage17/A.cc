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
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> mp(n);
  map<string, int> st;
  for (auto &i : mp)
    cin >> i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int j_id = j * k;
      string str = mp[i].substr(j_id, k);
      st[str]++;
    }
  }
  assert(st.size() == 2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int j_id = j * k;
      string sr = mp[i].substr(j_id, k);
      if (st[sr] == 1) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
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