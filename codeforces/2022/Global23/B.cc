#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll num = 0;
  for (auto &i : a) {
    cin >> i;
    num += i;
  }
  ll ans = 0;
  for (ll i = n - 1; i >= 0; --i) {
    if (num == 0)
      break;
    if (a[i] == 1) {
      num--;
    } else {
      a[i] = 1;
      ans++;
      num--;
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