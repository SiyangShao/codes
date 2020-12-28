#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll MOD = 998'244'353;
constexpr int N = 3010;
array<ll, N> frac;
void init() {
  frac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    frac[i] = frac[i - 1] * i % MOD;
  }
}
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].emplace_back(v), E[v].emplace_back(u);
  }
  vector<ll> f(n), g(n);
  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      dfs(v, u);
    }
    int siz = 0;
    vector<ll> s(n + 1);
    s[0] = 1;
    for (auto v : E[u]) {
      if (v == fa)
        continue;
      for (int i = siz; i >= 0; --i) {
        s[i + 1] = (s[i + 1] + s[i] * f[v] % MOD) % MOD;
        s[i] = s[i] * g[v] % MOD;
      }
      siz++;
    }
    for (int i = 0; i <= siz; ++i) {
      g[u] = (g[u] + frac[i] * s[i] % MOD) % MOD;
      f[u] = (f[u] + frac[i + 1] * s[i] % MOD) % MOD;
    }
  };
  dfs(0, 0);
  cout << g[0] << "\n";
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