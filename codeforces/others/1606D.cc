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
  int n, m;
  cin >> n >> m;
  vector mp(n, vector<int>(m));
  vector<multiset<int>> st(n);
  vector<int> mx(n), mi(n, 1e7);
  for (auto &i : mp)
    for (auto &j : i)
      cin >> j;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      st[i].emplace(mp[i][j]);
    }
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  for (int jj = 0; jj + 1 < m; ++jj) {
    multiset<int> lefRed, lefBlue, rigRed, rigBlue;
    for (int i = 0; i < n; ++i) {
      st[i].erase(st[i].find(mp[i][jj]));
      mx[i] = max(mx[i], mp[i][jj]);
      mi[i] = min(mi[i], mp[i][jj]);
      lefBlue.emplace(mx[i]);
      rigBlue.emplace(*st[i].begin());
    }
    ranges::sort(id, [&](int x, int y) {
      if (mx[x] != mx[y])
        return mx[x] > mx[y];
      return mi[x] > mi[y];
    });
    for (int u = 0; u + 1 < n; ++u) {
      int i = id[u];
      lefBlue.erase(lefBlue.find(mx[i]));
      rigBlue.erase(rigBlue.find(*st[i].begin()));
      lefRed.emplace(mi[i]);
      rigRed.emplace(*st[i].rbegin());
      if ((*lefRed.begin() > *lefBlue.rbegin()) &&
          (*rigRed.rbegin() < *rigBlue.begin())) {
        cout << "YES\n";
        vector<int> col(n);
        for (int j = 0; j <= u; ++j) {
          col[id[j]] = 1;
        }
        for (auto j : col) {
          if (j)
            cout << "R";
          else
            cout << "B";
        }
        cout << " ";
        cout << jj + 1 << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
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