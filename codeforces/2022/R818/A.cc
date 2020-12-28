#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
  ll n;
  cin >> n;
  ll bs1 = n / 3, bs2 = n / 2;
  cout << n + bs1 * 2 + bs2 * 2 << "\n";
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