#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll qpow(ll a, ll b) {
  ll ans = 1;
  a = (a % MOD + MOD) % MOD;
  while (b) {
    if (b & 1) {
      ans = a * ans % MOD;
    }
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
constexpr ll two = qpow(2, MOD - 2);
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<vector<ll>> E(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (ll i = 1; i < n; ++i) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  vector<ll> subtree(n, 0);
  ll cnt = 0;
  function<void(ll, ll)> dp = [&](ll u, ll fa) {
    ll sum = 0, squa = 0;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dp(v, u);
      sum = (sum + subtree[v]) % MOD;
      squa = (squa + subtree[v] * subtree[v] % MOD) % MOD;
      subtree[u] += subtree[v] * a[u] % MOD;
      subtree[u] %= MOD;
    }
    subtree[u] += a[u];
    subtree[u] %= MOD;
    cnt = (cnt + subtree[u]) % MOD;
    sum = sum * sum % MOD;
    ll tmp = (sum + MOD - squa) % MOD;
    tmp = tmp * two % MOD;
    tmp = tmp * a[u] % MOD;
    cnt = (cnt + tmp) % MOD;
  };
  dp(0, 0);
  cout << cnt << "\n";
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
