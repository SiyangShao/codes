#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using ppii = pair<ll, pii>;
constexpr ll inf = 1e16;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<ppii> edg(m);
  vector mp(n, vector<ll>(n, inf));
  for (auto &[w, path] : edg) {
    auto &[u, v] = path;
    cin >> u >> v >> w;
    u--, v--;
    mp[u][v] = mp[v][u] = 1;
  }
  for (ll i = 0; i < n; ++i) {
    mp[i][i] = 0;
  }
  for (ll k = 0; k < n; ++k) {
    for (ll i = 0; i < n; ++i) {
      for (ll j = 0; j < n; ++j) {
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[j][k]);
      }
    }
  }
  ll ans = inf;
  for (auto &[w, path] : edg) {
    auto [u, v] = path;
    ll len = min(mp[u][0] + mp[v][n-1] + 1, mp[u][n-1]+ mp[v][0] + 1);
    for(ll k = 0 ; k < n; ++k){
      len = min(len, min(mp[u][k], mp[v][k])+1 + mp[k][0] + mp[k][n-1] + 1);
    }
    ans = min(ans, len * w);
  }
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