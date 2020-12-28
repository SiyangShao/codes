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
    if (fa[u] != u)
      fa[u] = find(fa[u]);
    return fa[u];
  }
  bool same(int u, int v) { return find(u) == find(v); }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (siz[u] > siz[v])
      swap(u, v);
    fa[u] = v;
    siz[v] += siz[u];
  }
};
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), pos(n);
  for (auto &i : a)
    cin >> i, i--;
  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    dsu.merge(i, a[i]);
    pos[a[i]] = i;
  }
  for (int i = 0, j = 0; i < n; ++i) {
    if (dsu.same(i, 0))
      continue;
    while (j < i - 1 and a[j] < i)
      ++j;
    swap(a[j], a[pos[i]]);
    dsu.merge(i, 0);
  }
  for (auto i : a) {
    cout << i + 1 << " ";
  }
  cout << "\n";
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