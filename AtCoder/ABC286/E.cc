#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  vector<vector<int>> E(n);
  vector ans(n, vector<ll>(n, -1));
  vector d(n, vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == 'Y') {
        E[i].emplace_back(j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    vector<int> dis(n, -1);
    ans[i][i] = a[i];
    dis[i] = 0;
    queue<int> Q;
    Q.emplace(i);
    while (!Q.empty()) {
      auto u = Q.front();
      Q.pop();
      for (auto v : E[u]) {
        if (dis[v] == -1) {
          dis[v] = dis[u] + 1;
          Q.emplace(v);
          ans[i][v] = max(ans[i][v], ans[i][u] + a[v]);
        } else if (dis[v] == dis[u] + 1) {
          ans[i][v] = max(ans[i][v], ans[i][u] + a[v]);
        }
      }
    }
    d[i] = dis;
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (ans[u][v] == -1) {
      cout << "Impossible\n";
    } else {
      cout << d[u][v] << " " << ans[u][v] << "\n";
    }
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