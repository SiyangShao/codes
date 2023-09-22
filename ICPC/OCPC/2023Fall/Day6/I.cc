#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> E(n);
  int L = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[v].emplace_back(w, u);
    if (u > v) {
      L = v;
    }
  }

  vector<int> from(n, -1);
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    sort(E[i].begin(), E[i].end());
    from[i] = E[i][0].second;
    ans += E[i][0].first;
  }
  vector<int> vec;
  bool flag = false;
  {
    int u = L;
    while (u != 0) {
      vec.emplace_back(u);
      u = from[u];
      if (u == L) {
        flag = true;
        break;
      }
    }
  }
  if (!flag) {
    cout << ans << "\n";
    return;
  }
  vector<int> vis(n);
  for (auto u : vec) {
    vis[u] = 1;
  }
  ll base = ans;
  ans = 1e16;
  for (auto u : vec) {
    ll cnt = base - E[u][0].first;
    ll addition = 1e16;
    for (auto [w, v] : E[u]) {
      if (vis[v])
        continue;
      addition = min(addition, w);
    }
    cnt += addition;
    ans = min(ans, cnt);
  }
  assert(ans != 1e16);
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