#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n;
  cin >> n;
  vector<ll> x(n + 2), y(n + 2);
  x[0] = -2 * inf, x[n + 1] = 2 * inf;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  y[0] = 0, y[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
  }
  vector<ll> a(n + 2), b(n + 2);
  for (int i = 0; i <= n; ++i) {
    ll c = y[i + 1] - y[i];
    if (c < 0)
      a[i] = 0, b[i] = abs(c);
    else
      a[i] = abs(c), b[i] = 0;
  }
  deque<pair<ll, ll>> l, r;
  for (int i = 0; i <= n; ++i) {
    l.emplace_back(x[i] + 1, a[i]);
    r.emplace_back(x[i + 1] - 1, b[i]);
  }
  ll ans = inf;
  while (not l.empty() and not r.empty()) {
    auto [x1, n1] = l.front();
    auto [x2, n2] = r.front();
    l.pop_front(), r.pop_front();
    ll num = min(n1, n2);
    if (num != 0) {
      ans = min(ans, x2 - x1);
    }
    n1 -= num;
    n2 -= num;
    if (n1 != 0)
      l.emplace_front(x1, n1);
    if (n2 != 0)
      r.emplace_front(x2, n2);
  }
  cout << (ans == inf ? -1 : ans) << "\n";
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