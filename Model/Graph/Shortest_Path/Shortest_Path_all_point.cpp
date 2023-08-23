#include <bits/stdc++.h>
using namespace std;
struct Jason {
  using ll = long long;
  const ll INF = 1e16;
  ll n, m;
  vector<ll> dis, vis, cnt, h;
  vector<vector<pair<ll, ll>>> E;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
  auto spfa(ll s = 0) {
    h.assign(n + 1, INF);
    vis.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    queue<ll> q;
    q.push(s);
    vis[s] = 1;
    h[s] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      vis[u] = 0;
      for (auto [v, w] : E[u]) {
        if (h[v] > h[u] + w) {
          h[v] = h[u] + w;
          cnt[v] = cnt[u] + 1;
          if (cnt[v] >= n + 1) {
            return false;
          }
          if (!vis[v]) {
            q.push(v);
            vis[v] = 1;
          }
        }
      }
    }
    return true;
  }
  auto dijkstra(ll s = 0) {
    dis.assign(n + 1, INF);
    vis.assign(n + 1, 0);
    dis[s] = 0;
    Q.emplace(0, s);
    while (!Q.empty()) {
      auto [d, u] = Q.top();
      Q.pop();
      if (vis[u] == 1)
        continue;
      vis[u] = 1;
      for (auto [v, w] : E[u]) {
        w = w + h[u] - h[v];
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          Q.emplace(dis[v], v);
        }
      }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
      if (dis[i] == INF) {
        ans += i * INF;
      } else if (i == s) {
        ans += 0;
      } else {
        ans += i * (dis[i] + h[i] - h[s]);
      }
    }
    return ans;
  }
  auto solve() {
    cin >> n >> m;
    E.assign(n + 1, vector<pair<ll, ll>>());
    for (ll i = 0, u, v, w; i < m; ++i) {
      cin >> u >> v >> w;
      E[u].emplace_back(v, w);
      // E[v].emplace_back(u, w);
    }
    for (ll i = 1; i <= n; ++i) {
      E[0].emplace_back(i, 0);
    }
    if (!spfa(0)) {
      cout << "-1\n";
      return;
    }
    for (ll i = 1; i <= n; ++i) {
      cout << dijkstra(i) << "\n";
    }
  }
};