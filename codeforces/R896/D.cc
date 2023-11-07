#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
vector<pair<int, int>> ans;
void No() {
  cout << "No\n";
  ans.clear();
}
void Yes() {
  cout << "Yes\n";
  for (auto [u, v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
  ans.clear();
}
void add(int u, int v) { ans.emplace_back(u, v); }

auto solve() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &i : d) {
    cin >> i;
  }
  if (accumulate(d.begin(), d.end(), 0LL) != n * 2) {
    return No();
  }
  if (ranges::count(d, 2) == n) {
    for (int i = 0; i < n; ++i) {
      add(i, (i + 1) % n);
    }
    return Yes();
  }
  if (ranges::count(d, 2) == 0) {
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      if (d[i] > 1)
        a.emplace_back(i);
    }
    if (static_cast<int>(d.size()) == 1)
      return No();
    for (int i = 0, j = 0; i < static_cast<int>(a.size()); ++i) {
      add(a[i], a[(i + 1) % a.size()]);
      for (int k = 0; k < d[a[i]] - 2; ++k) {
        while (d[j] != 1)
          j++;
        add(a[i], j);
        j++;
      }
    }
    return Yes();
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  ranges::sort(p, [&](int i, int j) { return d[i] > d[j]; });
  for (int i = 0; i < 4; i++) {
    if (i >= n || d[p[i]] < (i < 2 ? 3 : 2)) {
      return No();
    }
  }
  int leaf = 0;
  while (d[p[leaf]] != 1)
    leaf++;
  add(p[0], p[1]);
  add(p[0], p[1]);
  d[p[0]] -= 2, d[p[1]] -= 2;
  array<vector<int>, 2> u;
  for (int i = 2; i < leaf; i++) {
    d[p[i]] -= 1;
    u[i % 2].emplace_back(p[i]);
  }
  vector<int> a;
  for (int t = 0; t < 2; t++) {
    int i = 0;
    if (t == 0 && u[0].size() > u[1].size()) {
      if (d[p[0]] >= 2) {
        add(p[0], u[0][0]);
        add(p[0], u[0][1]);
        d[p[0]] -= 2;
        i = 1;
      } else if (d[u[0][0]] >= 2) {
        add(p[0], u[0][0]);
        d[p[0]]--;
        if (u[0].size() <= 2) {
          return No();
        }
        add(u[0][0], u[0][1]);
        add(u[0][0], u[0][2]);
        d[u[0][0]] -= 2;
        i = 2;
      } else {
        return No();
      }
    } else {
      add(p[t], u[t][0]);
      d[p[t]]--;
    }
    while (i + 1 < (int)u[t].size()) {
      add(u[t][i], u[t][i + 1]);
      d[u[t][i]]--;
      i++;
    }
  }
  for (int i = 0; i < leaf; i++) {
    for (int j = 0; j < d[p[i]]; j++) {
      a.emplace_back(p[i]);
    }
  }
  for (int i = 0; i < (int)a.size(); ++i) {
    add(a[i], p[leaf + i]);
  }
  return Yes();
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