#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, k, b, s;
  cin >> n >> k >> b >> s;
  if (b * k > s || b * k + n * (k - 1) < s) {
    cout << "-1\n";
    return;
  }
  vector<ll> a(n, 0);
  a[0] = b * k;
  s -= a[0];
  for (ll i = 0; i < n; ++i) {
    if (s >= k - 1) {
      s -= k - 1;
      if (a[i] + k - 1 > 1e18) {
        s += k - 1;
      } else {
        a[i] += k - 1;
      }
    } else {
      a[i] += s;
      s = 0;
    }
  }
  if (s != 0) {
    cout << "-1\n";
    return;
  }
  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n";
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