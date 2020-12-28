#include <bits/stdc++.h>
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _) : n(_), fa(_) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool same(int u, int v) {
    u = find(u), v = find(v);
    return u == v;
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> b(n);
  for (auto &i : b) {
    cin >> i;
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int x, int y) { return b[x] > b[y]; });
  vector<vector<int>> E(n), G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  DSU dsu(n);
  vector<int> in(n);
  long long ans = 0, cur = 1e9, size = 0;
  for (auto u : id) {
    long long dif = cur - b[u];
    ans += dif * size;
    cur = b[u];
    size++;
    in[u] = 1;
    for (auto v : E[u]) {
      if (in[v] && !dsu.same(u, v)) {
        size--;
        dsu.merge(u, v);
      }
    }
  }
  ans += cur * size;
  cout << ans << "\n";
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