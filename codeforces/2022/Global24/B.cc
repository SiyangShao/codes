#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  ll g = a[0];
  for (int i = 1; i < n; ++i) {
    g = gcd(g, a[i] - a[i - 1]);
  }
  assert(a.back() % g == 0);
  cout << a.back() / g << "\n";
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