#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> col(n);
  for (auto &i : col)
    cin >> i;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  int ans = 0;
  for (int start = 0; start < n; ++start) {
    vector<int> dis(n * 2, -1);
    queue<tuple<int, int, int>> Q;
    Q.emplace(start, 0, 0);
    while (!Q.empty()) {
      auto [u, odd, d] = Q.front();
      Q.pop();
      if (dis[u + odd * n] != -1)
        continue;
      dis[u + odd * n] = d;
      for (auto v : E[u]) {
        Q.emplace(v, odd ^ (col[u] == col[v] ? 0 : 1), d + 1);
      }
    }
    // cerr << start << ":\n";
    for (int i = 0; i < n; ++i) {
      // cout << dis[i] << " " << dis[i + n] << "\n";
      if (dis[i] == -1 || dis[i + n] == -1) {
        ans = max(ans, max(dis[i], dis[i + n]) + k);
      } else {
        int x = dis[i], y = dis[i + n];
        if (x > y)
          swap(x, y);
        int dif = y - x;
        int add = min(dif, k);
        x += add;
        int newK = k - add;
        x += newK / 2;
        ans = max(ans, x);
      }
    }
  }
  cout << ans << "\n";
}