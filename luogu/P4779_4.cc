#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
// directed edge u->v, weight is w
// start point is s
auto adj_matrix_and_array() {
  ll n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<vector<ll>> mp(n, vector<ll>(n, inf));
  for (ll i = 0; i < n; ++i) {
    mp[i][i] = 0;
  }
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    mp[u][v] = w;
  }
  vector<ll> dis(n, inf), vis(n, 0);
  function<ll()> get_min = [&]() {
    ll id = -1, ans = inf;
    for (ll i = 0; i < n; ++i) {
      if (!vis[i] && dis[i] < ans) {
        ans = dis[i];
        id = i;
      }
    }
    return id;
  };
  dis[s] = 0;
  while (true) {
    ll u = get_min();
    if (u == -1) {
      break;
    }
    vis[u] = 1;
    for (ll v = 0; v < n; ++v) {
      if (dis[v] > dis[u] + mp[u][v]) {
        dis[v] = dis[u] + mp[u][v];
      }
    }
  }
  for (auto &i : dis) {
    cout << i << " ";
  }
}
auto adj_list_and_heap() {
  // adj list + mini heap
  ll n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<vector<pair<ll, ll>>> E(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
  vector<ll> dis(n, inf), vis(n, 0);
  dis[s] = 0;
  Q.emplace(dis[s], s);
  while (!Q.empty()) {
    auto [_, u] = Q.top();
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, d] : E[u]) {
      if (dis[v] > dis[u] + d) {
        dis[v] = dis[u] + d;
        Q.emplace(dis[v], v);
      }
    }
  }
  for (auto &i : dis) {
    cout << i << " ";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    // solve();
    adj_matrix_and_array();
  }
}