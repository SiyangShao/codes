#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> cheese(n);
  ll ans = 0;
  for (auto &[a, b] : cheese) {
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }
    // a > b
    ans += b * 2;
  }
  sort(cheese.begin(), cheese.end());
  ans += cheese.front().first + cheese.back().first;
  for (int i = 1; i < n; ++i) {
    ans += cheese[i].first - cheese[i - 1].first;
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