#include "bits/stdc++.h"
using namespace std;
template <class length> struct Difference_Constraints {
  int n;
  vector<vector<pair<int, length>>> E;
  vector<length> dis;
  vector<int> cnt, vis;
  Difference_Constraints(int _n)
      : n(_n), E(_n + 1), dis(_n + 1, numeric_limits<length>::max()),
        cnt(_n + 1), vis(_n + 1){};
  void add_condition(int u, int v, length y) {
    // xu - xv <= y
    E[v].emplace_back(u, y);
  }
  auto spfa(int s = 0) {
    queue<int> q;
    q.push(s);
    vis[s] = 1, dis[s] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      vis[u] = 0;
      for (auto [v, w] : E[u])
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          cnt[v] = cnt[v] + 1;
          if (cnt[v] > n)
            return false;
          if (!vis[v]) {
            q.push(v);
            vis[v] = 1;
          }
        }
    }
    return true;
  }
  auto solve() {
    for (int i = 1; i <= n; ++i)
      E[0].emplace_back(i, 0);
    if (spfa())
      for (int i = 1; i <= n; ++i)
        cout << dis[i] << " ";
    else
      cout << "NO\n";
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  Difference_Constraints<long long> G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long y;
    cin >> u >> v >> y;
    G.add_condition(u, v, y);
  }
  G.solve();
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