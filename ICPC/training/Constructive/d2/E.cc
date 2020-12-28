#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; ++i) {
      cout << n - i << " " << n + i << " ";
    }
    cout << "\n";
  } else {
    for (int i = 1; i <= n / 2; ++i) {
      cout << n - i + 3 * n - (i == n / 2 ? i + 1 : 0) << " "
           << n + i + 3 * n + (i == n / 2 ? i + 1 : 0) << " ";
    }
    cout << n + 3 * n << "\n";
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
