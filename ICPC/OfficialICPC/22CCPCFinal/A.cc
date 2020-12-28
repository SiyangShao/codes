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
auto solve() {
  int n;
  cin >> n;
  bool flag = false;
  vector<vector<int>> E(n * 2);
  for (int i = 0; i < n * 2 - 2; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u == v) {
      flag = true;
    }
    if (u > v)
      swap(u, v);
    E[u].emplace_back(v + n);
    E[v + n].emplace_back(u);
  }
  if (flag) {
    cout << "0\n";
    return;
  }
  for (int i = 1; i < n; ++i) {
    if (E[i + n].empty()) {
      cout << "0\n";
      return;
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (E[i].empty()) {
      cout << "0\n";
      return;
    }
  }
  ll ans = 1;
  vector<int> vis(n * 2, 0);
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (auto v : E[u]) {
      if (!vis[v])
        dfs(v);
    }
  };
  for (int i = 0; i + 1 < n; ++i) {
    if (!vis[i]) {
      dfs(i);
      ans = ans * 2 % MOD;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (!vis[i + n]) {
      dfs(i + n);
      ans = ans * 2 % MOD;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}