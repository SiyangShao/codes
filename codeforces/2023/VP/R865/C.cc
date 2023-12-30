#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[v].emplace_back(u);
  }
  vector<int> rnk(n);
  rnk[0] = 1;
  queue<int> Q;
  Q.emplace(0);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : E[u]) {
      if (!rnk[v]) {
        rnk[v] = rnk[u] + 1;
        Q.emplace(v);
      } else {
        assert(rnk[v] <= rnk[u] + 1);
      }
    }
  }
  dbg(rnk);
  vector<vector<int>> r(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!rnk[i]) {
      cout << "INFINITE\n";
      return;
    }
    r[rnk[i] - 1].emplace_back(i);
    ans += rnk[i];
  }
  cout << "FINITE\n";
  cout << ans << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= i; --j) {
      for (auto k : r[j]) {
        cout << k + 1 << " ";
      }
    }
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