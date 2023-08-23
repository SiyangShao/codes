#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, ll>>> E(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  vector<ll> dis(n, inf);
  dis[0] = 0;
  auto dijkstra = [&]() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
    for (ll i = 0; i < n; ++i) {
      Q.emplace(dis[i], i);
    }
    while (!Q.empty()) {
      auto [d, u] = Q.top();
      Q.pop();
      if (d > dis[u])
        continue;
      for (auto [v, w] : E[u]) {
        if (dis[v] > d + w) {
          dis[v] = d + w;
          Q.emplace(dis[v], v);
        }
      }
    }
  };
  /**
   * @brief
   * new_dis[i] = min(dis[j] + (i - j)^2)
   * Suppose the critical point for each i is c[i], then new_dis[i] =
   * min(dis[c[i]] + (c[i] - i)^2). Obviously, c[i] is non-decreasing. Thus we
   * could use divide and conquer to solve the problem
   */
  auto update = [&]() {
    auto new_dis = vector<ll>(n, inf);
    new_dis[0] = 0;
    /**
     * @brief
     * Suppose for range l-r, c[l] - c[r] is inside L-R. Thus, we choose middle
     * point mid and calculate the pivot, and solve the problem recursively
     */
    function<void(ll, ll, ll, ll)> dfs = [&](ll l, ll r, ll L, ll R) {
      if (l > r) {
        return;
      }
      if (l == r) {
        for (ll i = L; i <= R; ++i) {
          new_dis[l] = min(new_dis[l], dis[i] + abs(l - i) * abs(l - i));
        }
        return;
      }
      auto mid = (l + r) / 2;
      auto _mid_L = L;
      for (ll i = L; i <= R; ++i) {
        if (dis[i] + abs(i - mid) * abs(i - mid) < new_dis[mid]) {
          new_dis[mid] = dis[i] + abs(i - mid) * abs(i - mid);
          _mid_L = i;
        }
      }
      dfs(l, mid - 1, L, _mid_L);
      dfs(mid + 1, r, _mid_L, R);
    };
    dfs(1, n - 1, 0, n - 1);
    dis = move(new_dis);
  };
  dijkstra();
  for (ll i = 0; i < k; ++i) {
    update();
    dijkstra();
  }
  for (ll i = 0; i < n; ++i) {
    cout << dis[i] << " ";
  }
  cout << "\n";
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
