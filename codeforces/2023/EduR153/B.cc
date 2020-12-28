#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll m, k, a, b;
  cin >> m >> k >> a >> b;
  ll res = m % k;
  if (res >= a) {
    cout << res - a + max(0LL, (m - res) / k - b) << "\n";
  } else {
    m = (m - res) / k;
    a = (a - res) / k;
    m -= a;
    cout << max(0LL, m - b) << "\n";
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