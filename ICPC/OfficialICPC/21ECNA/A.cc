#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
constexpr int N = 100'010;
constexpr int inf = 1e9;
array<int, N> x;
array<vector<int>, N> frac;
auto init() {
  fill(x.begin(), x.end(), inf);
  x[1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      frac[j].emplace_back(i);
    }
  }
  for (int i = 2; i < N; ++i) {
    x[i] = min(x[i], x[i - 1] + 1);
    for (int j = 1; j <= i / 2; ++j) {
      x[i] = min(x[i], x[j] + x[i - j]);
    }
    for (auto j : frac[i]) {
      x[i] = min(x[i], x[j] + x[i / j]);
    }
    for (int k = 10; k <= i; k *= 10) {
      int j = i / k;
      if (i - j * k >= k / 10)
        x[i] = min(x[i], x[j] + x[i - j * k]);
    }
  }
}
auto solve() {
  int n;
  cin >> n;
  cout << x[n] << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}