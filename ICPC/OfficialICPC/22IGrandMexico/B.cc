#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e5 + 7;
auto solve() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> E(n);
  for (ll i = 1; i < n; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<ll> dis(n, -1), vis(n, 0);
  priority_queue<ll, vector<ll>, greater<>> Q;
  function<void(ll, ll)> dfs = [&](ll u, ll k) {
    assert(dis[u] < k);
    Q.emplace(u);
    dis[u] = k;
    if (k == 0) {
      return;
    }
    for (auto v : E[u]) {
      if (dis[v] >= k - 1)
        continue;
      dfs(v, k - 1);
    }
  };
  Q.emplace(0);
  while (!Q.empty()) {
    auto cur = Q.top();
    Q.pop();
    if (vis[cur])
      continue;
    vis[cur] = 1;
    cout << cur + 1 << " ";
    dfs(cur, k);
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