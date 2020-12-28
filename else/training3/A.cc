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
  DSU(int n) : fa(n), siz(n, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (siz[u] > siz[v]) {
      swap(u, v);
    }
    fa[u] = v;
    siz[v] += siz[u];
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    dsu.merge(u, v);
  }
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) == i) {
      ll siz = dsu.siz[i];
      sum += ll(siz) * (siz - 1) / 2;
    }
  }
  if (sum != m) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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