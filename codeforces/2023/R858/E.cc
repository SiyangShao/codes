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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> E(n);
  vector<ll> same(n);
  vector<int> fa(n, -1), dep(n, 0);
  for (int i = 1; i < n; ++i) {
    cin >> fa[i];
    fa[i]--;
    E[fa[i]].emplace_back(i);
  }
  function<void(int)> init = [&](int u) {
    same[u] += a[u] * a[u];
    for (auto v : E[u]) {
      same[v] += same[u];
      dep[v] = dep[u] + 1;
      init(v);
    }
  };
  init(0);
  map<pair<int, int>, ll> mp;
  const int blk = (int)sqrt(n);
  function<ll(int, int)> ask = [&](int u, int v) {
    if (u == v) {
      return same[u];
    }
    if (u > v)
      swap(u, v);
    if (dep[u] <= blk) {
      return a[u] * a[v] + ask(fa[u], fa[v]);
    } else {
      if (mp[{u, v}] == 0) {
        return mp[{u, v}] = a[u] * a[v] + ask(fa[u], fa[v]);
      } else {
        return mp[{u, v}];
      }
    }
  };
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << ask(u, v) << "\n";
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