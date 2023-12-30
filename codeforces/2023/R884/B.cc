#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
  } else if (n == 2) {
    cout << "1 2\n";
  } else {
    int num = (n - 3) / 2;
    cout << "3";
    for (int i = 0; i < num; ++i) {
      cout << " " << 4 + i;
    }
    cout << " 1";
    for (int i = 0; i < (n - 3) - num; ++i) {
      cout << " " << n - i;
    }
    cout << " 2\n";
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