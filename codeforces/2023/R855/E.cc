#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using i64 = long long;
struct DSU {
  int n;
  std::vector<int> fa;
  DSU(int _n) : n(_n), fa(_n) { std::iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u])
      fa[u] = find(fa[u]);
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    fa[u] = v;
  }
};
auto solve() {
  int n, k;
  std::string s, t;
  std::cin >> n >> k >> s >> t;
  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    if (i + k < n) {
      dsu.merge(i, i + k);
    }
    if (i + k + 1 < n) {
      dsu.merge(i, i + k + 1);
    }
  }
  int cnt = 0;
  std::vector<int> mp(n, -1);
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) == i) {
      mp[i] = cnt++;
    }
  }
  std::vector<std::vector<int>> scc(cnt);
  std::vector<std::multiset<char>> dif(cnt);

  for (int i = 0; i < n; ++i) {
    scc[mp[dsu.find(i)]].emplace_back(i);
    dif[mp[dsu.find(i)]].emplace(s[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (!dif[mp[dsu.find(i)]].contains(t[i])) {
      std::cout << "NO\n";
      return;
    }
    dif[mp[dsu.find(i)]].erase(dif[mp[dsu.find(i)]].find(t[i]));
  }
  std::cout << "YES\n";
}
auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int _ = 1;
  std::cin >> _;
  while (_--) {
    solve();
  }
}