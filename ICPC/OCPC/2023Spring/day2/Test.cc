#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll l, r;
  cin >> l >> r;
  if (l == r) {
    if (l == 1) {
      cout << "1\n";
    } else {
      cout << "-1\n";
    }
    return;
  }
  if (abs(r - l + 1) % 2 == 0) {
    for (ll i = l; i < r; i += 2) {
      cout << i + 1 << " " << i << " ";
    }
    cout << "\n";
    return;
  }
  if (gcd(l, r) == 1) {
    for (ll i = l; i < r; ++i) {
      cout << i + 1 << " ";
    }
    cout << l << "\n";
    return;
  }
  if (l % 2 == 0 && r % 2 == 0) {
    cout << "-1\n";
    return;
  }
  assert(l % 2 == 1 && r % 2 == 1);
  assert(gcd(l, r - 2) == 1);
  for (ll i = l; i < r - 2; ++i) {
    cout << i + 1 << " ";
  }
  cout << l << " " << r << " " << r - 1 << "\n";
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