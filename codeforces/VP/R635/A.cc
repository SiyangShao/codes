#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  vector<int> add(n), del(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  function<void(int, int)> dfs = [&](int u, int fa) {
    add[u] = add[fa] + 1;
    del[u] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
      del[u] += del[v];
    }
  };
  dfs(0, 0);
  priority_queue<ll> Q;
  for (int i = 0; i < n; ++i) {
    Q.emplace(add[i] - del[i]);
  }
  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += Q.top();
    Q.pop();
  }
  cout << ans << "\n";
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
