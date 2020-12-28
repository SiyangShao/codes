#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    for (int i = 0; i < n; ++i) {
      cout << 1 << " \n"[i + 1 == n];
    }
  } else {
    if (n == 2) {
      cout << "1 3\n";
    } else {
      cout << "13 2 8 1 ";
      for (int i = 4; i < n; ++i) {
        cout << 6 << " ";
      }
      cout << "\n";
    }
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
