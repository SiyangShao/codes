#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
using ld = long double;
constexpr ld CD = 0.89;
constexpr ld v = 5.25;
constexpr ld atk = 24;
constexpr ld eps = 1e-8;
auto solve() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> node(n);
  for (auto &[id, c] : node) {
    ll l, r, h, s;
    cin >> l >> r >> h >> s;
    id = max(l - 6, 0LL);
    c = static_cast<ll>(ceil((h + s) / atk));
  }
  ranges::sort(node, greater<>());
  ld l = 0, r = 2e12;
  function<bool(ld)> check = [&](ld x) {
    ll chance = 0, need = 0;
    for (auto [d, c] : node) {
      if (chance >= c) {
        chance -= c;
        c = 0;
        continue;
      }
      c -= chance;
      chance = 0;
      ld res = x - d / v;
      ll extra = static_cast<ll>(floor(res / CD));
      if (extra <= 0) {
        return false;
      }
      ll cur = (c + extra - 1) / extra;
      need += cur;
      chance += cur * extra - c;
    }
    return need <= m;
  };
  ld ans = r;
  while (l + eps <= r) {
    auto mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - eps;
      ans = min(ans, mid);
    } else {
      l = mid + eps;
    }
  }
  cout << fixed << setprecision(8) << ans << "\n";
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