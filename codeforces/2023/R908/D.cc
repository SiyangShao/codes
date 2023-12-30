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
  vector<vector<int>> ans(m);
  vector<int> cnt(n), a(m), b(m);
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    cnt[x - 1]++;
  }
  priority_queue<pair<int, int>> p;
  for (int i = 0; i < n; ++i) {
    if (cnt[i])
      p.emplace(cnt[i], i);
  }
  vector<tuple<int, int, int>> vec;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    vec.emplace_back(i, a[i], b[i]);
  }
  for (auto [id, len, d] : vec) {
    queue<int> q;
    for (int i = 0; i < len; ++i) {
      if (p.empty()) {
        cout << "-1\n";
        return;
      }
      auto [_, u] = p.top();
      p.pop();
      cnt[u]--;
      ans[id].push_back(u);
      q.emplace(u);
      if ((int)q.size() == d) {
        int v = q.front();
        q.pop();
        if (cnt[v]) {
          p.emplace(cnt[v], v);
        }
      }
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (cnt[v]) {
        p.emplace(cnt[v], v);
      }
    }
  }
  for (auto &i : ans) {
    for (auto &j : i) {
      cout << j + 1 << " ";
    }
    cout << "\n";
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