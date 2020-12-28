#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
vector<pair<ll, ll>> sp(ll x, ll y) {
  vector<pair<ll, ll>> ans;
  for (ll i = 10; i <= x; i *= 10) {
    ll prex = x / i;
    for (ll j = 10; j <= y; j *= 10) {
      ll prey = y / j;
      ll nx = x - prex * i + prey * i;
      ll ny = y - prey * j + prex * j;
      ans.emplace_back(nx, ny);
    }
  }
  return ans;
}
bool check(ll a, ll b, ll c, string_view op) {
  if (op == "+")
    return a + b == c;
  else
    return a * b == c;
}
auto solve() {
  ll a, b, c;
  string x, y;
  cin >> a >> x >> b >> y >> c;
  dbg(a, b, c);
  // swap a, b
  auto ab = sp(a, b);
  for (auto [na, nb] : ab) {
    auto nc = c;
    if (check(na, nb, nc, x)) {
      cout << na << " " << x << " " << nb << " = " << nc << "\n";
      return;
    }
  }
  dbg(ab);
  auto bc = sp(b, c);
  for (auto [nb, nc] : bc) {
    auto na = a;
    if (check(na, nb, nc, x)) {
      cout << na << " " << x << " " << nb << " = " << nc << "\n";
      return;
    }
  }
  dbg(bc);
  auto ac = sp(a, c);
  for (auto [na, nc] : ac) {
    auto nb = b;
    if (check(na, nb, nc, x)) {
      cout << na << " " << x << " " << nb << " = " << nc << "\n";
      return;
    }
  }
  dbg(ac);
  assert(false);
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