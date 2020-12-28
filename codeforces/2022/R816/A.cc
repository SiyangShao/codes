#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  if (n == m && n == 1) {
    cout << "0\n";
    return;
  }
  ll x = n - 1 + m - 1;
  ll y = min(n - 1, m - 1) + 1;
  cout << x + y << "\n";
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