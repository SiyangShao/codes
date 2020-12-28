#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  int L = 0, R = 0;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    if (l == k)
      L++;
    if (r == k)
      R++;
  }
  if (L > 0 && R > 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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