#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  iota(a.begin(), a.end(), 1);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    reverse(a.begin() + i, a.end());
    ll cnt = 0, max_num = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] * (j + 1) > max_num) {
        max_num = a[j] * (j + 1);
      }
      cnt += a[j] * (j + 1);
    }
    ans = max(ans, cnt - max_num);
    reverse(a.begin() + i, a.end());
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