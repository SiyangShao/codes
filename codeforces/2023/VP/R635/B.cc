#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 4e18;
auto solve() {
  int nr, ng, nb;
  cin >> nr >> ng >> nb;
  vector<ll> r(nr), g(ng), b(nb);
  for (auto &i : r)
    cin >> i;
  r.emplace_back(0), r.emplace_back(1e9 + 7);
  sort(r.begin(), r.end());
  for (auto &i : g)
    cin >> i;
  g.emplace_back(0), g.emplace_back(1e9 + 7);
  sort(g.begin(), g.end());
  for (auto &i : b)
    cin >> i;
  b.emplace_back(0), b.emplace_back(1e9 + 7);
  sort(b.begin(), b.end());
  ll ans = inf;
  auto cal = [&](ll x, ll y, ll z) {
    if (x == 0 || y == 0 || z == 0)
      return inf;
    if (x == (ll)1e9 + 7 || y == (ll)1e9 + 7 || z == (ll)1e9 + 7)
      return inf;
    return (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z);
  };
  for (auto i : g) {
    if (i == 0 || i == (ll)1e9 + 7)
      continue;
    auto r_r = lower_bound(r.begin(), r.end(), i);
    auto r_l = prev(r_r);
    auto b_r = lower_bound(b.begin(), b.end(), i);
    auto b_l = prev(b_r);
    ans = min(ans, cal(i, *r_r, *b_r));
    ans = min(ans, cal(i, *r_r, *b_l));
    ans = min(ans, cal(i, *r_l, *b_l));
    ans = min(ans, cal(i, *r_l, *b_r));
  }
  swap(g, r);
  for (auto i : g) {
    if (i == 0 || i == (ll)1e9 + 7)
      continue;
    auto r_r = lower_bound(r.begin(), r.end(), i);
    auto r_l = prev(r_r);
    auto b_r = lower_bound(b.begin(), b.end(), i);
    auto b_l = prev(b_r);
    ans = min(ans, cal(i, *r_r, *b_r));
    ans = min(ans, cal(i, *r_r, *b_l));
    ans = min(ans, cal(i, *r_l, *b_l));
    ans = min(ans, cal(i, *r_l, *b_r));
  }
  swap(g, b);
  for (auto i : g) {
    if (i == 0 || i == (ll)1e9 + 7)
      continue;
    auto r_r = lower_bound(r.begin(), r.end(), i);
    auto r_l = prev(r_r);
    auto b_r = lower_bound(b.begin(), b.end(), i);
    auto b_l = prev(b_r);
    ans = min(ans, cal(i, *r_r, *b_r));
    ans = min(ans, cal(i, *r_r, *b_l));
    ans = min(ans, cal(i, *r_l, *b_l));
    ans = min(ans, cal(i, *r_l, *b_r));
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
