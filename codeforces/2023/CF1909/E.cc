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
  vector<pair<int, int>> edg(m);
  for (auto &[u, v] : edg) {
    cin >> u >> v;
    u--, v--;
  }
  if (n >= 20) {
    cout << n << "\n";
    for (auto i : ranges::views::iota(1, n + 1)) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  vector<int> ans;
  auto check = [&](unsigned int s) {
    if (popcount(s) > n / 5)
      return;
    if (!ans.empty())
      return;
    vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
      if ((s >> i) & 1) {
        vis[i] = 1;
        for (int j = (i + 1); j <= n; j += i + 1) {
          s ^= 1 << (j - 1);
        }
      }
    }
    for (auto [u, v] : edg) {
      if (vis[u] && !vis[v]) {
        return;
      }
    }
    ans = vis;
  };
  for (int i = 0; i < n; ++i) {
    check(1 << i);
    for (int j = 0; j < i; ++j) {
      check((1 << i) | (1 << j));
      for (int k = 0; k < j; ++k) {
        check((1 << i) | (1 << j) | (1 << k));
      }
    }
  }
  if (ans.empty()) {
    cout << "-1\n";
  } else {
    cout << accumulate(ans.begin(), ans.end(), 0) << "\n";
    for (auto i : ranges::views::iota(0, n)) {
      if (ans[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";
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