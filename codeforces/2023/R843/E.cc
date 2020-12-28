#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  ll mx = 0, mn = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    sum += x;
    mx = max(mx, sum);
    mn = min(mn, sum);
  }
  cout << mx - mn << "\n";
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
