#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int dif = 0, dif_rev = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      dif++;
    }
  }
  reverse(t.begin(), t.end());
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      dif_rev++;
    }
  }
  if (dif == 0) {
    cout << "0\n";
    return;
  }
  if (dif_rev == 0) {
    cout << "2\n";
    return;
  }
  int ans = ((dif - 1) % 2 == 0 ? dif + dif - 1 : dif + dif);
  int ans_rev =
      ((dif_rev - 1) % 2 == 0 ? dif_rev + dif_rev : dif_rev + dif_rev - 1);
  cout << min(ans, ans_rev) << "\n";
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