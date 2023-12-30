#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k, g;
  cin >> n >> k >> g;
  ll half = (g + 1) / 2 - 1;
  ll total = k * g - (n - 1) * half;
  if (total <= 0) {
    cout << k * g << "\n";
    return;
  }
  ll ans = total / g + ((total % g) * 2 >= g ? 1 : 0);
  ll sum = ans * g;
  cout << k * g - sum << "\n";
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