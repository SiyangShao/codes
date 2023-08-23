#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  queue<pair<ll, ll>> black, white;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      if (i % 2 == j % 2) {
        black.emplace(i, j);
      } else {
        white.emplace(i, j);
      }
    }
  }
  function<void(pair<ll, ll>, ll)> output = [&](pair<ll, ll> p, ll x) {
    cout << x << " " << p.first << " " << p.second << endl;
  };
  while (!black.empty() || !white.empty()) {
    ll x;
    cin >> x;
    if (x == 1) {
      if (!black.empty()) {
        output(black.front(), 2);
        black.pop();
      } else {
        output(white.front(), 3);
        white.pop();
      }
    } else if (x == 2) {
      if (!white.empty()) {
        output(white.front(), 1);
        white.pop();
      } else {
        output(black.front(), 3);
        black.pop();
      }
    } else {
      if (!white.empty()) {
        output(white.front(), 1);
        white.pop();
      } else {
        output(black.front(), 2);
        black.pop();
      }
    }
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