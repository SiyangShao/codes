#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> h(n);
  for (auto &i : h)
    cin >> i;
  vector<vector<int>> E(n);
  vector<int> in(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    in[v]++;
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0)
      Q.emplace(i);
  }
  vector<int> topo;
  while (!Q.empty()) {
    auto u = Q.front();
    topo.emplace_back(u);
    Q.pop();
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0)
        Q.emplace(v);
    }
  }
  vector<ll> dp(n);
  for (auto u : topo | ranges::views::reverse) {
    for (auto v : E[u]) {
      dp[u] = max(dp[u], dp[v] + (h[v] - h[u] + k) % k);
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << "\n";
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  ranges::sort(p, [&](int x, int y) { return h[x] < h[y]; });
  ll ans = inf;
  for (int i = 0; i < n; ++i) {
    dp[i] += h[i]; // dp[i] means the end of the segment if i starts at day 0
  }
  ll res = *ranges::max_element(dp);
  for (auto u : p) {
    ans = min(ans, res - h[u]);
    res = max(res, dp[u] + k);
  }
  cout << ans << "\n";
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}