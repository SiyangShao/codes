#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m;
  ll p;
  cin >> n >> m >> p;
  vector<ll> w(n);
  for (auto &i : w) {
    cin >> i;
  }
  vector dis(n, vector<ll>(n, inf));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ll s;
    cin >> s;
    dis[u][v] = min(dis[u][v], s);
  }
  for (int i = 0; i < n; ++i) {
    dis[i][i] = 0;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](auto x, auto y) { return w[x] < w[y]; });
  vector dp(n + 1, vector<array<ll, 2>>(n, {inf, inf}));
  dp[0][0] = {0, -p};
  for (int i = 1; i <= n; ++i) {
    int u = id[i - 1];
    dbg(dis[u]);
    auto &cur = dp[i];
    const auto &pre = dp[i - 1];
    for (int v = 0; v < n; ++v) {
      cur[v] = min(cur[v], pre[v]);
      if (dis[u][v] == inf)
        continue;
      auto nd = max(0LL, (pre[u][1] + dis[u][v] + w[u] - 1) / w[u]);
      dbg(nd);
      cur[v] =
          min(cur[v], array{pre[u][0] + nd, pre[u][1] - nd * w[u] + dis[u][v]});
    }
  }
  cout << (dp[n][n - 1][0] >= inf ? -1 : dp[n][n - 1][0]) << "\n";
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
