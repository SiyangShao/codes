#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll n, m, q;
  cin >> n >> m >> q;
  const ll block = (ll)sqrt(n);
  vector<ll> a(n), b(q), dp(n), deg(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<pair<ll, ll>>> E(n), big(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    E[u].emplace_back(v, w);
    E[v].emplace_back(u, w);
    deg[u]++, deg[v]++;
  }
  for (auto &i : b) {
    cin >> i;
    i--;
  }
  vector<multiset<ll>> st(n);
  for (int i = 0; i < n; ++i) {
    for (auto [v, w] : E[i]) {
      if (deg[v] >= block) {
        big[i].emplace_back(v, w);
      }
    }
    if (deg[i] < block) {
      for (auto [v, w] : E[i]) {
        st[v].emplace(w);
      }
    }
  }
  reverse(b.begin(), b.end());
  for (auto u : b) {
    ll res = 1e16;
    for (auto &[v, w] : big[u]) { // all big nodes adj to u
      res = min(res, dp[v] + w);
    }
    if (!st[u].empty()) {
      res = min(res, *st[u].begin());
    }
    if (deg[u] < block) { // under sqrt(n) * log(n)
      for (auto &[v, w] : E[u]) {
        st[v].erase(st[v].find(dp[u] + w));
        st[v].emplace(res + w);
      }
    }
    dp[u] = res;
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dp[i] * a[i] % MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
}