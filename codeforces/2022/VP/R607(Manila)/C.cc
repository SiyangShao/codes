#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll k;
  cin >> k;
  k *= 2;
  vector<vector<pair<ll, ll>>> E(k);
  ll G = 0;
  for (int i = 1; i < k; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G += w;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
  }
  ll ans1 = 0, ans2 = 0;
  vector<ll> siz(k, 0);
  function<void(ll, ll, ll)> dfs = [&](ll u, ll fa, ll cst) {
    siz[u] = 1;
    for (auto [v, w] : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u, w);
      siz[u] += siz[v];
    }
    if (siz[u] % 2 == 0) {
      ans1 += cst;
    }
    ans2 += min(siz[u], k - siz[u]) * cst;
  };
  dfs(0, 0, 0);
  cout << G - ans1 << " " << ans2 << "\n";
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