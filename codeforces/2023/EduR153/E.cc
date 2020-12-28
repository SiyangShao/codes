#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto dijkstra(int n, vector<vector<pair<int, int>>> &E, int s) {
  vector<int> dis(n, 1e9), vis(n, 0);
  deque<pair<int, int>> Q;
  dis[s] = 0;
  Q.emplace_back(0, s);
  while (!Q.empty()) {
    auto [_, u] = Q.front();
    Q.pop_front();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, w] : E[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (w == 0) {
          Q.emplace_front(dis[v], v);
        } else {
          Q.emplace_back(dis[v], v);
        }
      }
    }
  }
  return dis;
}
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<vector<pair<int, int>>> E(n + 26 * 26);
  for (int i = 0; i + 1 < n; ++i) {
    E[i].emplace_back(i + 1, 1);
    E[i + 1].emplace_back(i, 1);
    int mid = (s[i] - 'a') * 26 + (s[i + 1] - 'a') + n;
    E[i].emplace_back(mid, 0);
    E[mid].emplace_back(i, 1);
  }
  vector<vector<int>> dis(26 * 26);
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      dis[i * 26 + j] = dijkstra(n + 26 * 26, E, n + i * 26 + j);
    }
  }
  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (l > r) {
      swap(l, r);
    }
    int ans = r - l;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        ans = min(ans, dis[i * 26 + j][l] + dis[i * 26 + j][r] - 1);
      }
    }
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