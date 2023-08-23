#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int blk = 5000;
auto solve() {
  /**
   * Observation: The delete order of the node is similar to the topo sort order
   * if we take the deg[i] - a[i] as degree. If we build such a dag, ANY
   * sequence of removal is equal to a valid topo sort. Consider the progress of
   * topo sort, if two nodes are connected (has edge), they must be removed in
   * order (e.g, if has edge u-v, u must be removed before v or after v.
   * pair<u,v> won't be nice). Thus, we could create a unique DAG and notice
   * that any valid sequence is also the valid topo order in this DAG. The
   * question then turns to calculate the reachable point pairs, which can be
   * done by bitmask dp on the topo order.
   *
   */
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    a[i] = (int)E[i].size() - a[i];
    if (a[i] == 0) {
      Q.emplace(i);
    }
  }
  vector<int> pos(n), topo;
  for (int i = 0; i < n; ++i) {
    auto u = Q.front();
    Q.pop();
    topo.emplace_back(u);
    pos[u] = i;
    for (auto v : E[u]) {
      a[v]--;
      if (a[v] == 0) {
        Q.emplace(v);
      }
    }
  }
  vector<vector<int>> G(n);
  for (int u = 0; u < n; ++u) {
    // cout << u + 1 << ": ";
    for (auto v : E[u]) {
      if (pos[v] > pos[u]) {
        G[u].emplace_back(v);
        // cout << v + 1 << " ";
      }
    }
    // cout << "\n";
  }
  vector<bitset<blk>> dp(n);
  ll ans = (ll)n * (n + 1) / 2;
  for (int i = 0; i < n; i += blk) {
    for (auto u : topo) {
      if (u >= i && u < i + blk) {
        dp[u][u - i] = true;
      }
      for (auto v : G[u]) {
        dp[v] |= dp[u];
      }
    }
    for (int j = 0; j < n; ++j) {
      ans -= (ll)dp[j].count();
      dp[j].reset();
    }
  }
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