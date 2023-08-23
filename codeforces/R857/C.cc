#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
auto solve() {
  int n;
  cin >> n;
  vector<int> k(n);
  vector a(n, vector<int>());
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
    a[i].resize(k[i]);
    for (auto &j : a[i]) {
      cin >> j;
    }
  }
  vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    val[i] = *max_element(a[i].begin(), a[i].end());
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int x, int y) { return val[x] < val[y]; });
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  vector<int> ans(val.size(), 0);
  for (auto i : id) {
    int x = *max_element(a[i].begin(), a[i].end());
    auto it = lower_bound(val.begin(), val.end(), x);
    if (it == val.begin()) {
      int pre = 0, cnt = 0;
      for (auto j : a[i]) {
        if (j > pre) {
          pre = j;
          cnt++;
        }
      }
      ans[0] = max(ans[0], cnt);
    } else {
      vector<int> cur;
      for (auto j : a[i]) {
        if (cur.empty() || j > cur.back()) {
          cur.emplace_back(j);
        }
      }
      int cnt = 0;
      int m = (int)cur.size();
      for (int j = 0; j < m; ++j) {
        auto pre = lower_bound(val.begin(), it, cur[j]);
        if (pre == val.begin()) {
          cnt = max(cnt, m - j);
        } else {
          cnt = max(cnt, ans[pre - val.begin() - 1] + m - j);
        }
      }
      ans[it - val.begin()] = max(ans[it - val.begin()], cnt);
    }
  }
  cout << ans.back() << "\n";
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
