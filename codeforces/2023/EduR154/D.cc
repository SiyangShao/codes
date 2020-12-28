#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> num(n + 1);
  num[n - 1] = 1, num[n] = 1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] < a[i + 1]) {
      num[i] = num[i + 1];
    } else {
      num[i] = num[i + 1] + 1;
    }
  }
  int ans = num[0] - 1;
  int lef = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || a[i] >= a[i - 1]) {
      lef++;
    }
    ans = min(ans, lef + num[i + 1] - 1);
  }
  cout << ans << "\n";
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