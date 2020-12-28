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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> dis(n, 0), vis(n, 0);
  queue<int> Q;
  Q.emplace(0);
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    for (auto v : E[u]) {
      if (vis[v])
        continue;
      vis[v] = 1;
      Q.emplace(v);
      dis[v] = dis[u] + 1;
    }
  }
  vector<int> lowDeg(n);
  constexpr ll inf = 1e16;
  vector<vector<int>> level(n);
  set<pair<ll, int>> base;
  for (int u = 0; u < n; ++u) {
    // base = max(base, a[u] - b[u] * (dis[u] + 1));
    base.emplace(a[u] - b[u] * (dis[u] + 1), u);
    level[dis[u]].emplace_back(u);
  }
  vector<ll> type3(n, -inf), type2(n, -inf), type2Ans(n, -inf);
  for (int i = n - 1; i >= 0; --i) {
    const auto &vec = level[i];
    if (vec.empty())
      continue;
    for (auto u : vec) {
      type2[u] = max(type2[u], a[u] - b[u] * dis[u]);
    }
    for (auto u : vec) {
      for (auto v : E[u]) {
        if (dis[v] == dis[u]) {
          type2Ans[u] = max(type2Ans[u], type2[v]);
        }
      }
    }
    for (auto u : vec) {
      for (auto v : E[u]) {
        if (dis[v] < dis[u]) {
          type3[v] = max(type3[v], max(a[u] - b[u] * (dis[u] - 1), type3[u]));
          type2[v] = max(type2[v], type2[u]);
          type2Ans[v] = max(type2Ans[v], type2Ans[u]);
        }
      }
    }
  }
  ranges::sort(E[0]);
  for (auto u : E[0]) {
    base.erase({a[u] - b[u] * (dis[u] + 1), u});
    ll ans = max({base.rbegin()->first, type3[u], type2Ans[u]});
    base.emplace(a[u] - b[u] * (dis[u] + 1), u);
    cout << ans << "\n";
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