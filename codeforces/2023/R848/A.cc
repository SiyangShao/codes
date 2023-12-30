#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    if (i + 1 != n) {
      if (a[i] == -1 && a[i + 1] == -1) {
        flag = 2;
      } else if (a[i] == -1 || a[i + 1] == -1) {
        flag = max(flag, 1);
      }
    }
    ans += a[i];
  }
  if (flag == 2) {
    ans += 4;
  } else if (flag == 0) {
    ans -= 4;
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