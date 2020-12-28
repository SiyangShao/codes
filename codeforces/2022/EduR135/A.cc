#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  iota(b.begin(), b.end(), 0);
  for (auto &i : a) {
    cin >> i;
  }
  sort(b.begin(), b.end(), [&](auto x, auto y) { return a[x] > a[y]; });
  cout << b[0] + 1 << "\n";
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