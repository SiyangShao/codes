#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
ll qpow(ll x, ll y) {
  x %= MOD;
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y /= 2;
  }
  return res;
}
auto solve() {
  cout<<qpow(MOD, MOD-2)<<"\n";
  // ll n;
  // cin >> n;
  // vector<vector<ll>> E(n);
  // for (ll i = 1; i < n; ++i) {
  //   ll u;
  //   cin >> u;
  //   u--;
  //   E[u].emplace_back(i);
  // }
  // vector<pair<ll, ll>> dp(n, {0, 0});
  // for (ll i = 0; i < n; ++i) {
  //   if (E[i].empty()) {
  //     // i is leaf
  //     dp[i] = {1, 0};
  //   }
  // }
  // function<void(ll)> dfs = [&](ll u) {
  //   if (!E[u].empty())
  //     dp[u].second = 1;
  //   for (auto v : E[u]) {
  //     dfs(v);
  //     dp[u].second *= (dp[v].first + dp[v].second) % MOD;
  //     dp[u].second %= MOD;
  //   }
  //   for (auto v : E[u]) {
  //     // take v to u
  //     if (dp[v].first == 0)
  //       continue;
  //     dp[u].first += dp[v].first * dp[u].second % MOD *
  //                    qpow((dp[v].first + dp[v].second) % MOD, MOD - 2) % MOD;
  //     dp[u].first %= MOD;
  //   }
  // };
  // dfs(0);
  // cout << (dp[0].first + dp[0].second) % MOD << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // int _ = 1;
  solve();
}