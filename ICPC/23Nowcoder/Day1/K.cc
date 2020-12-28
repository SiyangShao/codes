#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
constexpr ll inf = 1e9;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<ll> dis(n + m * 2, inf), vis(n + m * 2);
  vector<int> fa(n + m * 2, -1);
  vector<vector<int>> G(n + m * 2);
  dis[0] = 0;
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> Q;
  Q.emplace(dis[0], 0, -1);
  while (!Q.empty()) {
    auto [d, u, f] = Q.top();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    fa[u] = f;
    for (auto v : E[u]) {
      if (dis[v] > d + 1) {
        dis[v] = d + 1;
        Q.emplace(dis[v], v, u);
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << fa[i] + 1 << " ";
  // }
  // cout << "\n";
  int cnt = n;
  for (int u = 0; u < n; ++u) {
    if (dis[u] == inf)
      continue;
    for (auto v : E[u]) {
      if (u == fa[v]) {
        G[u].push_back(v);
      } else if (v != fa[u]) {
        G[u].emplace_back(cnt);
        dis[cnt] = dis[u] + 1;
        fa[cnt] = u;
        cnt++;
      }
    }
  }
  // cout << cnt << "\n";
  // for (int i = 0; i < cnt; ++i) {
  //   cout << i + 1 << ": ";
  //   for (auto v : G[i]) {
  //     cout << v + 1 << " ";
  //   }
  //   cout << "\n";
  // }
  function<ll(int)> dp = [&](int u) {
    if (dis[u] > k) {
      return 0LL;
    }
    ll ans = 1; // self
    if (dis[u] == k)
      return 1LL;
    for (auto v : G[u]) {
      if (G[v].empty()) {
        ans += k - dis[u];
      } else {
        ans += dp(v);
      }
    }
    return ans;
  };
  cout << dp(0) << "\n";
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