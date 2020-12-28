#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;

constexpr int N = (1 << 20) + 5;
int a[N], b[N], T[N << 2], res[N];

void build(int k, int l, int r) {
  if (l == r) return (void)(T[k] = 1);
  int mid = (l + r) >> 1;
  build(k * 2, l, mid);
  build(k * 2 + 1, mid + 1, r);
  T[k] = T[k * 2] + T[k * 2 + 1];
}

std::vector<std::pair<int, int>> cur;

void mdf(int k, int l, int r, int x) {
  if (l == r) return (void)(T[k] = 0);
  int mid = (l + r) >> 1;
  if (x <= mid) mdf(k * 2, l, mid, x); else mdf(k * 2 + 1, mid + 1, r, x);
  T[k] = T[k * 2] + T[k * 2 + 1];
  cur.emplace_back(T[k], (r - l + 1) - T[k]);
}

auto solve() {
  int n, k;
  cin >> n >> k;
  int nn = (1 << n);
  for (int i = 1; i <= nn; ++i) {
    cin >> a[i];
    b[a[i]] = i;
  }
  build(1, 1, nn);
  T[0] = nn;
  for (int i = 1; i <= nn; ++i) {
    cur.clear();
    mdf(1, 1, nn, b[i]);
    dbg(cur);
    res[b[i]] = 0;
    for (auto [x, y] : cur) if (x <= k && x <= i - y) ++res[b[i]];
  }
  for (int i = 1; i <= nn; ++i) std::cout << res[i] << ' ';
  std::cout << '\n';
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