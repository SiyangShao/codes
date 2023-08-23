#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "NO\n";
    return;
  }
  if (n % 2 == 1) {
    cout << "YES\n";
    ll a = m - (n - 1);
    for (ll i = 0; i < n - 1; ++i) {
      cout << "1 ";
    }
    cout << a << "\n";
  } else {
    if (m % 2 == 1) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    ll a = m - (n - 2);
    assert(a % 2 == 0);
    a /= 2;
    for (ll i = 0; i < n - 2; ++i) {
      cout << "1 ";
    }
    cout << a << " " << a << "\n";
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