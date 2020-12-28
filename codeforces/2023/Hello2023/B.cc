#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      cout << "1 -1 ";
    }
    cout << "\n";
  } else {
    int x = (n + 1) / 2, y = n / 2;
    x--, y--;
    assert(x != 0 && y != 0);
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        cout << -y << " ";
      } else {
        cout << x << " ";
      }
    }
    cout << "\n";
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
