#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
auto solve() {
  ll n, m;
  cin >> n >> m;
  cout << "? ";
  cout << n * 2 + 2 << "\n";
  cout << 0 << " " << m + 1 << "\n" << 0 << " " << 0 << "\n";
  for (ll i = 1; i < n; ++i) {
    cout << i << " " << m << "\n" << i << " " << 0 << "\n";
  }
  cout << n << " " << m << "\n" << n << " " << m + 1 << endl;
  ld y;
  cin >> y;
  y *= m;
  y -= 0.5;
  cout << "? ";
  cout << m * 2 + 2 << "\n";
  cout << n + 1 << " " << 0 << "\n" << 0 << " " << 0 << "\n";
  for (ll i = 1; i < m; ++i) {
    cout << n << " " << i << "\n" << 0 << " " << i << "\n";
  }
  cout << n << " " << m << "\n" << n + 1 << " " << m << endl;
  ld x;
  cin >> x;
  x *= n;
  x -= 0.5;
  cout << setprecision(8) << "! ";
  cout << x << " " << y << endl;
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