#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> e(k);
  vector<int> vis(n, 0);
  vector<ll> ans(n, inf);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
  for (auto &i : e) {
    cin >> i;
    i--;
    ans[i] = 0;
    Q.emplace(ans[i], i);
  }
  vector<int> d(n);
  for (auto &i : d) {
    cin >> i;
  }
  for (auto i : e) {
    d[i] = 0;
  }
  vector<vector<pair<int, ll>>> E(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  while (!Q.empty()) {
    auto [_, u] = Q.top();
    Q.pop();
    d[u]--;
    if (d[u] >= 0)
      continue;
    ans[u] = min(ans[u], _);
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto [v, w] : E[u]) {
      Q.emplace(ans[u] + w, v);
    }
  }
  if (!vis[0] || ans[0] == inf) {
    cout << "-1\n";
  } else {
    cout << ans[0] << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}