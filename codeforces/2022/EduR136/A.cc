#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m;
  cin >> n >> m;
  if (n == 1 || m == 1) {
    cout << "1 1\n";
  } else if (n == 2 || n == 3) {
    int x = min(2LL, n);
    cout << 2 << " " << x << "\n";
  } else if (m == 2 || m == 3) {
    int x = min(2LL, n);
    cout << x << " " << 2 << "\n";
  } else {
    cout << "1 1\n";
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