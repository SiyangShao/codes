#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll inf = 2e18;
auto solve() {
  int n;
  cin >> n;
  ll a, b, c;
  cin >> a >> b >> c;
  vector<ll> A(n);
  for (auto &i : A)
    cin >> i;
  array<ll, 8> pre, cur;
  fill(pre.begin(), pre.end(), inf);
  pre[0] = 0;
  auto cost = [&](ll x, ll y) {
    ll md = (x + y - 1) / y;
    return md * y - x;
  };
  for (auto x : A) {
    fill(cur.begin(), cur.end(), inf);
    cur[0] = min(cur[0], pre[0]);
    cur[1] = min(pre[1], pre[0] + cost(x, a));
    cur[2] = min(pre[2], pre[0] + cost(x, b));
    cur[3] = min(pre[3], pre[0] + cost(x, c));
    cur[4] = min({pre[4], pre[0] + cost(x, lcm(a, b)), pre[1] + cost(x, b),
                  pre[2] + cost(x, a)});
    cur[5] = min({pre[5], pre[0] + cost(x, lcm(a, c)), pre[1] + cost(x, c),
                  pre[3] + cost(x, a)});
    cur[6] = min({pre[6], pre[0] + cost(x, lcm(c, b)), pre[2] + cost(x, c),
                  pre[3] + cost(x, b)});
    cur[7] = min({pre[7], pre[0] + cost(x, lcm(lcm(a, b), c)),
                  pre[1] + cost(x, lcm(b, c)), pre[2] + cost(x, lcm(a, c)),
                  pre[3] + cost(x, lcm(a, b)), pre[4] + cost(x, c),
                  pre[5] + cost(x, b), pre[6] + cost(x, a)});
    dbg(cur);
    swap(pre, cur);
  }
  cout << pre[7] << "\n";
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