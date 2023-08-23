#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto output(ll n, ll k, ll p = 0) {
  for (ll i = 0; i < n; ++i) {
    if ((i + p) % k == 0) {
      cout << "X";
    } else {
      cout << ".";
    }
  }
  cout << "\n";
}
auto solve() {
  ll n, k, r, c;
  cin >> n >> k >> r >> c;
  ll p = k - (c + r - 1 + k) % k;
  for (ll i = 1; i <= n; ++i) {
    output(n, k, i + p);
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