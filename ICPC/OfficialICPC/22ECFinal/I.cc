#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m, k, d;
  cin >> n >> m >> k >> d;
  k--;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<int> dis(n, n + 1), toK(n, n + 1);
  {
    vector<int> vis(n, 0);
    queue<int> Q;
    Q.emplace(n - 1);
    dis[n - 1] = 1;
    while (!Q.empty()) {
      auto u = Q.front();
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto v : E[u]) {
        if (dis[v] > dis[u] + 1) {
          dis[v] = dis[u] + 1;
          Q.emplace(v);
        }
      }
    }
  }
  function<ll(int)> cal = [&](int u) {
    ll cnt = dis[u] / d;
    ll res = dis[u] % d;
    ll sumx = (1LL + d) * d / 2;
    sumx *= cnt;
    sumx += ((ll)d + (ll)d - res + 1) * res / 2;
    return sumx;
  };
  {
    vector<int> vis(n, 0);
    queue<int> Q;
    Q.emplace(k);
    toK[k] = 0;
    while (!Q.empty()) {
      auto u = Q.front();
      Q.pop();
      if (vis[u])
        continue;
      vis[u] = 1;
      for (auto v : E[u]) {
        if (toK[v] > toK[u] + 1) {
          toK[v] = toK[u] + 1;
          Q.emplace(v);
        }
      }
    }
  }
  // cout << "DIS\n";
  // for (int i = 0; i < n; ++i) {
  //   cout << dis[i] << " " << toK[i] << "\n";
  // }
  constexpr ll inf = 1e16;
  ll sum = inf;
  vector<ll> ans(n, inf);
  vector<int> vis(n);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  ans[0] = 0;
  for (auto v : E[0]) {
    ans[v] = 0;
    pq.emplace(0, v);
  }
  while (!pq.empty()) {
    auto [_, u] = pq.top();
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    // cout << u + 1 << " " << ans[u] << " " << cal(u) << "\n";
    if (toK[u] >= d) {
      ans[u] += cal(u);
      sum = min(sum, ans[u]);
      continue;
    } else {
      ans[u] += d - toK[u];
    }
    for (auto v : E[u]) {
      if (ans[v] > ans[u]) {
        ans[v] = ans[u];
        pq.emplace(ans[v], v);
      }
    }
  }
  sum = min(sum, ans[n - 1]);
  cout << sum << "\n";
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