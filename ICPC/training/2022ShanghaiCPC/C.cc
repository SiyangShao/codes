#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto case1(ll s, ll c) {
  ll bs = c * c + c;
  bs /= 2;
  bs = min(bs, s);
  ll m = bs / (c + 1) + (bs % (c + 1) == 0 ? 0 : 1);
  ll x = min(bs - 1 - (c + 1) * (m - 1), c - m) + 1;
  ll y = x + (m - 1) * (c + 1);
  return (s - y) * (s + y + 1) / 2 + c * m * (x + y) / 2;
}
auto case2(ll s, ll c) {
  ll bs = c * c + c;
  bs /= 2;
  ll res = min(s, c);
  bs = min(bs, s);
  ll m;
  if (s >= c) {
    m = (bs - c) / (c + 1) + 1;
  } else {
    m = 1;
  }
  ll x = res - m + 1;
  ll y = x + (m - 1) * (c + 1);
  return (s - y) * (s + y + 1) / 2 + c * m * (x + y) / 2;
}
auto solve() {
  ll s, c;
  cin >> s >> c;
  // Not Drink: sum of (s + ... + s-c)
  // Drink: s * c
  // when s >= (c^2+c)/2, not drink
  cout << max(case1(s, c), case2(s, c)) << "\n";
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