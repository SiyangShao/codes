#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
vector<int> a, val;
vector<ll> siz, ans;
vector<vector<int>> E;
vector<array<ll, 2>> dp;
void init(int u, int fa) {
  siz[u] = 1;
  dp[u][val[u]] = 0;
  for (auto v : E[u]) {
    if (v == fa)
      continue;
    init(v, u);
    siz[u] += siz[v];
    dp[u][val[u]] += dp[v][val[u]];
  }
  dp[u][!val[u]] = dp[u][val[u]] + siz[u];
}
void transfer(int u, int fa, const ll base) {
  ans[u] += base * min(dp[u][0], dp[u][1]);
  for (auto v : E[u]) {
    if (v == fa)
      continue;
    ll x1 = dp[u][0], y1 = dp[u][1], x2 = dp[v][0], y2 = dp[v][1];
    ll z1 = siz[u], z2 = siz[v];
    siz[u] -= siz[v];
    dp[u][val[u]] -= dp[v][val[u]];
    dp[u][!val[u]] = dp[u][val[u]] + siz[u];
    dp[v][val[v]] += dp[u][val[v]];
    siz[v] += siz[u];
    dp[v][!val[v]] = dp[v][val[v]] + siz[v];
    transfer(v, u, base);
    dp[u][0] = x1, dp[u][1] = y1, dp[v][0] = x2, dp[v][1] = y2;
    siz[u] = z1, siz[v] = z2;
  }
};
auto solve() {
  int n;
  cin >> n;
  a = vector<int>(n);
  val = vector<int>(n);
  for (auto &i : a) {
    cin >> i;
  }
  E = vector<vector<int>>(n);
  siz = vector<ll>(n);
  ans = vector<ll>(n, 0);
  dp = vector<array<ll, 2>>(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v);
    E[v].emplace_back(u);
  }
  for (int t = 0; t < 20; ++t) {
    const ll multiply = (1LL << t);
    for (int i = 0; i < n; ++i) {
      val[i] = (a[i] >> t) & 1;
    }

    init(0, 0);
    // dbg(dp);
    transfer(0, 0, multiply);
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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