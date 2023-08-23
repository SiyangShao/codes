#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a(n), vis(n, 0);
  for (auto &i : a) {
    cin >> i;
  }
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ans += a[i];
    }
  }
  for (ll i = 0; i < n; ++i) {
    if (vis[i])
      continue;
    if (s[i] == '1') {
      ll r = i;
      ll mi = 1e16;
      for (ll j = i; j < n; ++j) {
        if (s[j] == '1') {
          vis[j] = 1;
          r = max(r, j);
          mi = min(mi, a[j]);
        } else {
          break;
        }
      }
      if (i > 0 && mi < a[i - 1]) {
        ans += a[i - 1] - mi;
      }
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