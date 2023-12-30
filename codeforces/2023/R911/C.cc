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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> tree(n);
  for (auto &[l, r] : tree) {
    cin >> l >> r;
    l--, r--;
  }
  vector<int> dep(n), fa(n, -1);
  function<void(int)> dfs = [&](int u) {
    auto [l, r] = tree[u];
    if (l == -1 && r == -1)
      dep[u] = 0;
    if (l != -1) {
      fa[l] = u;
      dfs(l);
      dep[u] = dep[l] + 1;
    }
    if (r != -1) {
      fa[r] = u;
      dfs(r);
      dep[u] = dep[r] + 1;
    }
    if (l != -1 && r != -1) {
      dep[u] = min(dep[l], dep[r]) + 1;
    }
  };
  dfs(0);
  int cur = 0;
  int ans = 0;
  for(auto i : s){

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