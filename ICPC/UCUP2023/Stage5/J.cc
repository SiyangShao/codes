#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 1024;
array<bitset<N>, N> E;
bitset<N> del;
constexpr ll MOD = 998'244'353;
auto solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    E[i].reset();
  }
  del.reset();
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u][v] = E[v][u] = true;
  }
  ll ans = 1;
  for (int u = 0; u < n; ++u) {
    if (del[u])
      continue;
    del[u] = true;
    bool isol = true;
    for (int v = u + 1; v < n; ++v) {
      
    }
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