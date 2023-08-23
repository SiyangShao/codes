#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  int len = n / 2;
  if (n % 2 == 1) {
    cout << "7";
  } else {
    cout << "1";
  }
  for (int i = 1; i < len; ++i) {
    cout << "1";
  }
  cout << "\n";
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