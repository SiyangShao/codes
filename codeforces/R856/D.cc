#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr ll N = 1e6 + 7;
array<ll, N> frac, inv_frac;
bitset<N> vis;
vector<ll> pri;
ll qpow(ll x, ll y) {
  x %= MOD;
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
void init() {
  vis[0] = vis[1] = true;
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (auto j : pri) {
      if (i * j >= N)
        break;
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
  frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
  inv_frac[N - 1] = qpow(frac[N - 1], MOD - 2);
  for (ll i = N - 1; i > 0; --i) {
    inv_frac[i - 1] = inv_frac[i] * i % MOD;
  }
}
ll A(ll x, ll y) { return frac[x] * inv_frac[x - y] % MOD; }
ll C(ll x, ll y) { return A(x, y) * inv_frac[y] % MOD; }
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(2ul * n);
  for (auto &i : a)
    cin >> i;
  sort(a.begin(), a.end());
  vector<pair<ll, ll>> b;
  for (auto i : a) {
    if (b.empty() || i != b.back().first) {
      b.emplace_back(i, 1);
    } else {
      b.back().second++;
    }
  }
  vector<pair<ll, ll>> prime;
  for (auto i : b) {
    if (!vis[i.first]) {
      prime.emplace_back(i);
    }
  }
  vector dp(prime.size(), vector<ll>(n + 1, -1));
  function<ll(ll, ll)> dfs = [&](ll cur, ll res) {
    if (cur == (ll)prime.size()) {
      return res == 0 ? 1LL : 0LL;
    }
    if (dp[cur][res] != -1) {
      return dp[cur][res];
    }
    dp[cur][res] = inv_frac[prime[cur].second] * dfs(cur + 1, res) % MOD;
    if (res) {
      dp[cur][res] +=
          inv_frac[prime[cur].second - 1] * dfs(cur + 1, res - 1) % MOD;
      dp[cur][res] %= MOD;
    }
    return dp[cur][res];
  };
  ll ans = dfs(0, n);
  for (auto [x, y] : b) {
    if (vis[x]) {
      ans = ans * inv_frac[y] % MOD;
    }
  }
  ans = ans * frac[n] % MOD;
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  // cin >> _;
  while (_--) {
    solve();
  }
}