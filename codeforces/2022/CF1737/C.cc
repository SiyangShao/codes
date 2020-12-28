#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> r(3), c(3);
  vector<pair<ll, ll>> pos(3);
  for (ll i = 0; i < 3; ++i) {
    cin >> r[i] >> c[i];
    pos[i] = {r[i], c[i]};
  }
  ll x, y;
  cin >> x >> y;
  sort(r.begin(), r.end());
  sort(c.begin(), c.end());
  ll R = r[0], C = c[0];
  if (r[0] != r[1]) {
    assert(r[1] == r[2]);
    R = r[1];
  }
  if (c[0] != c[1]) {
    assert(c[1] == c[2]);
    C = c[1];
  }
  if (abs(x - R) % 2 == 1 && abs(y - C) % 2 == 1) {
    cout << "NO\n";
    return;
  } else if (x == R || y == C) {
    cout << "YES\n";
    return;
  }
  vector<pair<ll, ll>> dui;
  for (ll i = 0; i < 3; ++i) {
    if (R != pos[i].first || C != pos[i].second) {
      dui.emplace_back(pos[i]);
    }
  }
  assert(dui.size() == 2);
  assert(dui[0].first != dui[1].first && dui[0].second != dui[1].second);
  if (dui[0].second > dui[1].second) {
    swap(dui[0], dui[1]);
  }
  auto [lx, ly] = dui[0];
  auto [rx, ry] = dui[1];
  if (lx == 2 && ly == 1 && rx == 1 && ry == 2 && R == 1 && C == 1) {
    cout << "NO\n";
    return;
  }
  if (lx == n && ly == n - 1 && rx == n - 1 && ry == n && R == n && C == n) {
    cout << "NO\n";
    return;
  }
  if (lx == n - 1 && ly == 1 && rx == n && ry == 2 && R == n && C == 1) {
    cout << "NO\n";
    return;
  }
  if (lx == 1 && ly == n - 1 && rx == 2 && ry == n && R == 1 && C == n) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
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