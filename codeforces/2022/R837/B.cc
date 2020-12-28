#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (auto(i) = a; (i) < n; ++(i))
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> not_friend(m);
  vector<int> left(n, -1);
  for (auto &[l, r] : not_friend) {
    cin >> l >> r;
    if (l > r) {
      swap(l, r);
    }
    l--, r--;
    left[r] = max(left[r], l);
  }
  ll ans = 0;
  rep(i, 0, n) {
    if (i != 0) {
      left[i] = max(left[i], left[i - 1]);
    }
    // from left[i] + 1 to i
    ans += (i - left[i]);
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