#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, b, s, r;
  cin >> n >> b >> s >> r;
  vector<vector<pair<int, ll>>> E(n), revE(n);
  for (int i = 0; i < r; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    u--, v--;
    E[u].emplace_back(v, l);
    revE[v].emplace_back(u, l);
  }
  vector<ll> dis(n, 1e16), revDis(n, 1e16);
  {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
    vector<bool> vis(n, false);
    Q.emplace(0, b);
    dis[b] = 0;
    while (!Q.empty()) {
      auto [d, u] = Q.top();
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = true;
      for (auto [v, l] : E[u]) {
        if (dis[v] > dis[u] + l) {
          dis[v] = dis[u] + l;
          Q.emplace(dis[v], v);
        }
      }
    }
    fill(vis.begin(), vis.end(), false);
    Q.emplace(0, b);
    revDis[b] = 0;
    while (!Q.empty()) {
      auto [d, u] = Q.top();
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = true;
      for (auto [v, l] : revE[u]) {
        if (revDis[v] > revDis[u] + l) {
          revDis[v] = revDis[u] + l;
          Q.emplace(revDis[v], v);
        }
      }
    }
  }
  vector<ll> sum(b);
  for (int i = 0; i < b; ++i) {
    sum[i] = dis[i] + revDis[i];
  }
  ranges::sort(sum);
  for (int i = 1; i < b; ++i) {
    sum[i] += sum[i - 1];
  }
  vector dp(b + 1, vector<ll>(s + 1, 1e16));
  
}