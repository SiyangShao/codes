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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  for (auto i : ranges::views::iota(1, n)) {
    int p;
    cin >> p;
    p--;
    E[p].emplace_back(i);
  }
  auto up = [&](multiset<int> &ms, int &offset) {
    auto f = *ms.rbegin();
    ms.extract(f);
    ms.emplace(f + 2);
    offset--;
    while (*ms.begin() + offset < 0)
      ms.erase(ms.begin());
  };
  vector<multiset<int>> ms(n);
  vector<int> offset(n);
  function<void(int)> dfs = [&](int u) {
    if (E[u].empty()) {
      ms[u].emplace(0);
      return;
    }
    for (auto v : E[u])
      dfs(v);
    for (auto v : E[u]) {
      up(ms[v], offset[v]);
      if (ms[v].size() > ms[u].size()) {
        swap(ms[v], ms[u]);
        swap(offset[v], offset[u]);
      }
      for (auto x : ms[v]) {
        ms[u].emplace(x + offset[v] - offset[u]);
      }
    }
    dbg(u + 1, offset[u], ms[u]);
  };
  dfs(0);
  int ans = (n - 1) * 2;
  vector<int> res;
  for (auto x : ms[0]) {
    res.emplace_back(x + offset[0]);
  }
  dbg(res);
  ranges::reverse(res);
  for (int i = 0; i <= k && i < (int)res.size(); ++i) {
    ans -= res[i];
  }
  cout << ans << "\n";
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