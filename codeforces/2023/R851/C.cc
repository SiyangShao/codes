#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  int x = n / 2;
  vector<int> l(n), r(n);
  iota(l.begin(), l.end(), 1);
  iota(r.begin(), r.end(), n + 1);
  for (int i = 0; i < n; ++i) {
    cout << l[i] << " " << r[(i + x) % n] << "\n";
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