#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
auto solve() {
  ll n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  ll bs = qpow(2, n - 1);
  ll ans = 0;
  function<int(int, int)> dfs = [&](int u, int fa) {
    int dep = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dep = max(dep, dfs(v, u) + 1);
    }
    ans = ans + bs * dep;
    ans %= MOD;
    return dep;
  };
  dfs(0, 0);
  cout << ans << "\n";
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