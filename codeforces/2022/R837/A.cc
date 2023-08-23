#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (auto(i) = a; (i) < n; ++(i))
auto solve() {
  ll n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  if (a[0] == a[n - 1]) {
    cout << n * (n - 1) << "\n";
  } else {
    ll x = 1, y = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[0]) {
        x++;
      } else {
        break;
      }
    }
    for (ll i = n - 2; i >= 0; --i) {
      if (a[i] == a[n - 1]) {
        y++;
      } else {
        break;
      }
    }
    cout << x * y * 2 << "\n";
  }
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