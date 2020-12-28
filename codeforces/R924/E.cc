#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 250010;
int ceil_pow2(int n) {
  int x = 0;
  while (n) {
    n >>= 1;
    x++;
  }
  return x - 1;
}
const int siz = ceil_pow2(N) + 1;
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n), c(n);
  vector<vector<int>> pos(n);
  bitset<N> vis, tmp;
  vector<bitset<N>> f(siz);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> c[i];
    c[i]--;
    vis[x[i]] = true;
    pos[c[i]].emplace_back(i);
  }
  for (int i = 0; i < n; ++i) {
    for (auto p : pos[i]) {
      tmp[x[p]] = true;
    }
    for (auto p : pos[i]) {
      f[ceil_pow2(p + 1)] |= (vis ^ tmp) >> x[p];
    }
    for (auto p : pos[i]) {
      tmp[x[p]] = false;
    }
  }
  while (q--) {
    int p;
    cin >> p;
    int ans = 0;
    for (int i = 0; i < siz; ++i) {
      if (f[i][p]) {
        ans = 1 << i;
        break;
      }
    }
    cout << ans << "\n";
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