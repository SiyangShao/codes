#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, m;
  cin >> n >> m;
  if (n & 1) {
    for (int i = 0; i < m; ++i) {
      cout << (i % 2 == 0 ? 'x' : 'o');
    }
    cout << "\n";
    n--;
  }

  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; ++j) {
      if (j % 5 == 4) {
        cout << 'o';
      } else {
        cout << 'x';
      }
    }
    cout << "\n";
    for (int j = 0; j < m; ++j) {
      if (j % 5 == 4) {
        cout << 'x';
      } else {
        cout << 'o';
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