#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int DIF = 500;
constexpr ll MOD = 998'244'353;
int n, k;
vector<vector<int>> E;
vector<vector<ll>> dp;
vector<unordered_map<int, ll>> dp2;
vector<int> siz;
inline void norm(ll &x) {
  if (x >= MOD)
    x -= MOD;
  return;
}
void dfs_small(int u, int fa) {
  dp[u][1] = 1;
  for (auto v : E[u]) {
    if (v == fa)
      continue;
    dfs_small(v, u);
    vector<ll> nxt(k + 2);
    for (int i = 0; i <= min(k + 1, siz[u]); ++i) {
      nxt[i] += dp[u][i] * dp[v][k] % MOD;
      norm(nxt[i]);
      nxt[i] += dp[u][i] * dp[v][k + 1] % MOD;
      norm(nxt[i]);
      for (int j = 0; j <= min(k + 1, siz[v]) && i + j <= k + 1; ++j) {
        nxt[i + j] += dp[u][i] * dp[v][j] % MOD;
        norm(nxt[i + j]);
      }
    }
    siz[u] += siz[v];
    swap(dp[u], nxt);
  }
}
void dfs_large(int u, int fa) {
  dp2[u][1] = 1;
  for (auto v : E[u]) {
    if (v == fa)
      continue;
    dfs_large(v, u);
    unordered_map<int, ll> nxt;
    for (auto [i, x] : dp2[u]) {
      if (dp2[v].contains(k)) {
        nxt[i] += x * dp2[v][k] % MOD;
        norm(nxt[i]);
      }
      if (dp2[v].contains(k + 1)) {
        nxt[i] += x * dp2[v][k + 1] % MOD;
        norm(nxt[i]);
      }
      for (auto [j, y] : dp2[v]) {
        if (i + j <= k + 1) {
          nxt[i + j] += x * y % MOD;
          norm(nxt[i + j]);
        }
      }
    }
    swap(dp2[u], nxt);
  }
}
auto solve() {
  cin >> n >> k;
  E = vector<vector<int>>(n);
  siz = vector<int>(n, 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  if (k < DIF) {
    dp = vector<vector<ll>>(n, vector<ll>(k + 2, 0));
    dfs_small(0, 0);
    ll ans = dp[0][k] + dp[0][k + 1];
    norm(ans);
    cout << ans << "\n";
  } else {
    dp2 = vector<unordered_map<int, ll>>(n);
    dfs_large(0, 0);
    ll ans = dp2[0][k] + dp2[0][k + 1];
    norm(ans);
    cout << ans << "\n";
  }
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