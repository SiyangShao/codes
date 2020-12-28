#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> d(n);
  for (auto &i : d) {
    cin >> i;
  }
  vector<ll> a(n);
  a[0] = d[0];
  for (ll i = 1; i < n; ++i) {
    a[i] = a[i - 1] + d[i];
  }
  for (ll i = n - 1; i > 0; --i) {
    if (d[i] != 0 && a[i] >= 2 * d[i]) {
      cout << "-1\n";
      return;
    }
  }
  for (auto &i : a) {
    cout << i << " ";
  }
  cout << "\n";
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