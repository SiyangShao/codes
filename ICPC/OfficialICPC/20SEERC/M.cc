#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k, m;
  cin >> n >> k >> m;
  vector<vector<ll>> E(n);
  vector<ll> in(n, 0), ans(n * k), a(n * k);
  for (int i = 0; i < m; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    // E[u].emplace_back(v);
    // in[v]++;
  }
  vector<ll> cnt(n, 0);
  for (auto &i : a) {
    cin >> i;
    i--;
    cnt[i]++;
    cout << cnt[i] << " ";
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