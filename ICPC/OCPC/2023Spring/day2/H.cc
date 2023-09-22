#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  assert(m >= 1);
  vector<vector<ll>> E(n);
  vector<ll> deg(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  ll mx = *max_element(deg.begin(), deg.end()),
     mi = *min_element(deg.begin(), deg.end());
  if (mx == mi && mx == n - 1) {
    cout << "YES\n";
    return;
  }
  if (n == 4 && m == 4 && mx == mi && mx == 2) {
    cout << "YES\n";
    return;
  }
  if (n == 4 && m == 2 && mx == mi && mx == 1) {
    cout << "YES\n";
    return;
  }
  // if (n == 3 && m == 1) {
  //   cout << "YES\n";
  //   return;
  // }
  if (mi == 0) {
    ll no_edge_point = 0;
    for (ll i = 0; i < n; ++i) {
      if (deg[i] == 0) {
        no_edge_point++;
      }
    }
    if (no_edge_point > 1) {
      cout << "NO\n";
      return;
    }
    for (ll i = 0; i < n; ++i) {
      if (deg[i] != 0 && deg[i] != n - 2) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
  }
  if (mx == n - 1) {
    ll center = -1;
    for (ll i = 0; i < n; ++i) {
      if (deg[i] == mx) {
        if (center != -1) {
          cout << "NO\n";
          return;
        }
        center = i;
      }
    }
    for (ll i = 0; i < n; ++i) {
      if (i == center)
        continue;
      if (deg[i] != 1 || E[i][0] != center) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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