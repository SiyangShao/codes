#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 1e7;
bitset<N> vis;
vector<int> pri;
void init(int n = N) {
  for (int i = 2; i < n; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (auto j : pri) {
      if (1ll * i * j >= n)
        break;
      vis[i * j] = true;
      if (i % j == 0) {
        break;
      }
    }
  }
}

struct MaximumMatching {
  int n, m;
  vector<vector<int>> E;
  vector<bool> vis;
  vector<int> link;
  MaximumMatching(int _n, int _m) : n(_n), m(_m), E(_n), vis(_m), link(_m){};
  bool dfs(int u) {
    vis[u] = true;
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = true;
      if (link[v] == -1 || dfs(link[v])) {
        link[v] = u;
        link[u] = v;
        return true;
      }
    }
    return false;
  };
  int solve() {
    fill(link.begin(), link.end(), -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      // dfs(i) x times means add x points same as point i in the map
      if (link[i] == -1)
        if (dfs(i)) {
          fill(vis.begin(), vis.end(), 0);
          cnt++;
        }
    }
    return cnt;
  }
};
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  MaximumMatching G(n, n);
  vector<bool> can(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      if (!vis[a[i] + a[j]]) {
        can[i] = can[j] = true;
        G.E[i].emplace_back(j);
      }
    }
  }
  int matching = G.solve();
  int res = 0;
  dbg(G.link);
  for (int i = 0; i < n; ++i) {
    if (can[i] && G.link[i] == -1) {
      dbg(i);
      res++;
    }
  }
  dbg(matching, res);
  if (matching >= k) {
    cout << k * 2 << "\n";
  } else {
    res = min(res, k - matching);
    cout << matching * 2 + res << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}