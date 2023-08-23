#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n;
  cin >> n;
  vector<ll> c(n);
  for (auto &i : c) {
    cin >> i;
  }
  vector<ll> x, y;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      x.emplace_back(c[i]);
    } else {
      y.emplace_back(c[i]);
    }
  }
  ll ansx = -inf, ansy = -inf;
  if (!x.empty()) {
    ranges::sort(x, greater<>());
    ansx = x[0];
    for (int i = 1; i < (int)x.size(); ++i) {
      if (x[i] > 0) {
        ansx += x[i];
      }
    }
  }
  if (!y.empty()) {
    ranges::sort(y, greater<>());
    ansy = y[0];
    for (int i = 1; i < (int)y.size(); ++i) {
      if (y[i] > 0) {
        ansy += y[i];
      }
    }
  }
  cout << max(ansx, ansy) << "\n";
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