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
  ll p;
  cin >> n >> p;
  vector<ll> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  ll ans = 0;
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, [&](int x, int y) { return b[x] < b[y]; });
  deque<pair<int, int>> Q;
  for (auto i : id) {
    if (Q.empty()) {
      ans += p;
    } else {
      auto [x, y] = Q.front();
      Q.pop_front();
      if (y < p) {
        ans += y;
        x--;
      } else {
        ans += p;
      }
      if (x != 0) {
        Q.emplace_front(x, y);
      }
    }
    Q.emplace_back(a[i], b[i]);
  }
  cout << ans << "\n";
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