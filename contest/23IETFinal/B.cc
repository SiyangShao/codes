#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e9;
auto solve() {
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  ll ans = 0;
  for (int rt = 0; rt < n; ++rt) {
    queue<int> Q;
    Q.emplace(rt);
    vector<ll> dis(n, inf), vis(n, 0);
    dis[rt] = 0;
    while (!Q.empty()) {
      auto u = Q.front();
      vis[u] = 1;
      Q.pop();
      for (auto [v, w] : E[u]) {
        if (vis[v])
          continue;
        dis[v] = max(w, dis[u]);
        Q.emplace(v);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i == rt)
        continue;
      ans += dis[i] + 1;
    }
  }

  ans /= 2;
  ans -= n - 1;
  cout << ans << "\n";
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