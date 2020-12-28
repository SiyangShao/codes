#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
struct DSU {
  vector<int> fa, siz;
  stack<pair<int, int>> st;
  int set_number;
  DSU(int n) : fa(n), siz(n, 1), set_number(n) {
    iota(fa.begin(), fa.end(), 0);
  }
  int find(int u) {
    if (u == fa[u])
      return u;
    return find(fa[u]);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (siz[u] > siz[v]) {
      swap(u, v);
    }
    st.emplace(u, v);
    if (u == v)
      return true;
    set_number--;
    fa[u] = v;
    siz[v] += siz[u];
    return false;
  }
  void pop() {
    assert(!st.empty());
    auto [u, v] = st.top();
    st.pop();
    if (u == v) {
      return;
    }
    set_number++;
    fa[u] = u;
    siz[v] -= siz[u];
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<int> l(n);
  for (auto &i : l)
    cin >> i;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<int> id(n), rev_id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return l[i] < l[j]; });
  for (int i = 0; i < n; ++i) {
    rev_id[id[i]] = i;
  }
  DSU lef(n), rig(n);
  for (int i = n - 1; i >= 0; --i) {
    int u = id[i];
    for (auto v : E[u]) {
      if (rev_id[v] > rev_id[u]) {
        rig.merge(u, v);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    // i is in rig
    int u = id[i];
    if (i != 0 && l[u] != l[id[i - 1]]) {
      int lef_number = i, rig_number = n - i;
      int lef_set = lef.set_number - rig_number;
      int rig_set = rig.set_number - lef_number;
      if (min(lef_number, rig_number) >= lef_set + rig_set - 1) {
        cout << l[id[i - 1]] << "\n";
        return;
      }
    }
    // i now in lef
    for (auto v : E[u]) {
      if (rev_id[v] > rev_id[u]) {
        rig.pop();
      }
    }
    for (auto v : E[u]) {
      if (rev_id[v] < rev_id[u]) {
        lef.merge(u, v);
      }
    }
  }
  cout << "-1\n";
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