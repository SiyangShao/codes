#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto b = a;
  int len = q - p;
  for (int i = 0; i <= len; ++i) {
    b[r + i - 1] = a[p + i - 1];
    b[p + i - 1] = a[r + i - 1];
  }
  for (auto &i : b) {
    cout << i << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}