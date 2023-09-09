#include <bits/stdc++.h>
#define ONLINE_JUDGE
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
  vector<vector<int>> p(n, vector<int>(n));
  vector<int> pos(n, 1), rev(n, n - 1);
  vector<int> is_leaf(n);
  for (auto &i : p) {
    for (auto &j : i) {
      cin >> j;
      j--;
    }
  }
  set<pair<int, int>> st;
  function<void(int, int)> add = [&](int u, int v) {
    if (u > v) {
      st.emplace(v, u);
    } else {
      st.emplace(u, v);
    }
  };
  for (int t = 0; t < n; ++t) {
    for (int i = 0; i < n; ++i) {
      if (is_leaf[i])
        continue;
      while (pos[i] < n && is_leaf[p[i][pos[i]]]) {
        pos[i]++;
      }
      if (pos[i] < n)
        add(i, p[i][pos[i]]);
    }
    for (int i = 0; i < n; ++i) {
      if (is_leaf[i])
        continue;
      if (rev[i] >= 0)
        is_leaf[p[i][rev[i]]] = 1;
    }
    for (int i = 0; i < n; ++i) {
      if (is_leaf[i])
        continue;
      while (rev[i] >= 0 && is_leaf[p[i][rev[i]]]) {
        rev[i]--;
      }
    }
  }
  dbg(st);
  assert((int)st.size() == n - 1);
  for (auto [u, v] : st) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}