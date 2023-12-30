#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    if (i <= q) {
      i = 1;
    } else {
      i = 0;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == 1)
      a[i] += a[i - 1];
  }
  ll ans = 0;
  for (auto i : a) {
    if (i >= k) {
      ans += i - k + 1;
    }
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