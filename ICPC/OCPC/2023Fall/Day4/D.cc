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
  vector<int> fa, size;
  DSU(int n) : fa(n), size(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (fa[u] != u) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return true;
    if (size[u] > size[v]) {
      swap(u, v);
    }
    fa[u] = v;
    size[v] += size[u];
    return false;
  }
  int get_size(int u) { return size[find(u)]; }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
    deg[u]++, deg[v]++;
  }
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    st.emplace(deg[i], i);
  }
  vector<int> vis(n);
  vector<int> order;
  while (!st.empty()) {
    auto [_, u] = *st.rbegin();
    st.erase({_, u});
    vis[u] = 1;
    order.emplace_back(u);
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      st.erase({deg[v], v});
      deg[v]--;
      st.emplace(deg[v], v);
    }
  }
  reverse(order.begin(), order.end());
  DSU dsu(n);
  fill(vis.begin(), vis.end(), 0);
  vector<vector<int>> ans(n);
  for (auto u : order) {
    vis[u] = 1;
    int block_size = 1;
    for (auto v : E[u]) {
      if (vis[v] && !dsu.merge(u, v)) {
        ans[u].emplace_back(v);
      }
      if (vis[v]) {
        block_size++;
      }
    }
    dbg(block_size);
    if (block_size != dsu.get_size(u)) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  for (auto u : order) {
    cout << u + 1 << " ";
    cout << ans[u].size() << " ";
    for (auto i : ans[u]) {
      cout << i + 1 << " ";
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