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
  vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    a[i] ^= a[i - 1];
  }
  vector<array<int, 2>> vec;
  vec.emplace_back(array{-1, -1});
  auto add = [&](int x) {
    int v = 0;
    for (int i = 19; i >= 0; --i) {
      int j = (x >> i) & 1;
      if (vec[v][j] == -1) {
        vec[v][j] = static_cast<int>(vec.size());
        vec.emplace_back(array{-1, -1});
      }
      v = vec[v][j];
    }
  };
  auto get = [&](int x) {
    int v = 0;
    for (int i = 19; i >= 0; --i) {
      int j = (x >> i) & 1;
      if (~vec[v][j ^ 1])
        j ^= 1;
      x ^= j << i;
      v = vec[v][j];
    }
    return x;
  };
  for (auto i : a) {
    add(i);
  }
  for (int i = 0; i < n; ++i) {
    if (get(i) == n - 1) {
      for (auto j : a) {
        cout << (i ^ j) << " ";
      }
      cout << "\n";
      return;
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