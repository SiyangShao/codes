#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, c;
  cin >> n >> c;
  vector<ll> a(n);
  vector<ll> num(110, 0);
  for (auto &i : a) {
    cin >> i;
    num[i]++;
  }
  ll ans = 0;
  for (ll i = 0; i <= 100; ++i) {
    ans += min(c, num[i]);
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