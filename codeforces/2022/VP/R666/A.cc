#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (n == 1) {
    cout << "1 1\n";
    cout << -a[0] << "\n";
    cout << "1 1\n0\n1 1\n0\n";
  } else {
    cout << "1 1\n";
    cout << -a[0] << "\n";
    a[0] = 0;
    cout << "1 " << n << "\n";
    for (ll i = 0; i < n; ++i) {
      cout << -n * a[i] << " ";
    }
    cout << "\n";
    cout << "2 " << n << "\n";
    for (ll i = 1; i < n; ++i) {
      cout << (n - 1) * a[i] << " ";
    }
    cout << "\n";
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