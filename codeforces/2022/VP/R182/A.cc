#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n * 2 - 1);
  ll neg = 0, zero = 0;
  for (auto &i : a) {
    cin >> i;
    if (i < 0) {
      neg++;
    } else if (i == 0) {
      zero++;
    }
  }
  if (!(neg % 2 == 0 || (neg >= n && (neg - n) % 2 == 0) || n % 2 == 1)) {
    ll ans = 0, mx = 1e16;
    for (auto &i : a) {
      ans += abs(i);
      mx = min(mx, abs(i));
    }
    cout << ans - mx * 2 << "\n";
  } else {
    ll ans = 0;
    for (auto &i : a) {
      ans += abs(i);
    }
    cout << ans << "\n";
  }
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