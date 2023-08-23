#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 100010;
auto solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> ans;
  for (ll i = 0; i < n; ++i) {
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ans.emplace_back(x1, x2);
  }
  sort(ans.begin(), ans.end());
  ll x = 0, cnt = 0;
  for (auto &[l, r] : ans) {
    if (l > x) {
      x = r;
      cnt += r - l;
    } else {
      cnt += max(0LL, r - x);
      x = max(r, x);
    }
  }
  cout << cnt << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}