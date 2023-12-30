#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int x, y, n;
  cin >> x >> y >> n;
  int sum = (1 + n - 1) * (n - 1) / 2;
  if (x + sum > y) {
    cout << "-1"
         << "\n";
    return;
  }
  vector<int> a(n);
  int dif = 1;
  a[0] = x;
  a[n - 1] = y;
  for (int i = n - 2; i > 0; --i) {
    a[i] = a[i + 1] - dif;
    dif++;
  }
  for (auto i : a) {
    cout << i << " ";
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