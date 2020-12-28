#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1, 0), r(n + 1, 0), s(n + 1, 0);
  vector<ll> ss(n + 1, 0), sr(n + 1, 0);
  r[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (ll i = 1; i <= n; ++i) {
    r[i] = r[i - 1];
    while (r[i] <= n && a[r[i]] >= r[i] - i + 1)
      r[i]++;
    s[i] = s[i - 1];
    if (s[i] < r[i] + 1)
      s[i] = min(r[i] + 1, n + 1);
    while (s[i] <= n && a[s[i]] >= s[i] - i + 1)
      s[i]++;
  }
  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    ans += r[i] - i;
  }
  for (ll i = 1; i <= n; i++) {
    sr[i] = sr[i - 1] + r[i];
    ss[i] = ss[i - 1] + s[i] - r[i];
  }
  ll q;
  cin >> q;
  while (q--) {
    ll k, x;
    cin >> k >> x;
    if (x < a[k]) {
      ll p = lower_bound(r.begin() + 1, r.end(), k) - r.begin();
      ll q = k - x + 1;
      if (q <= p) {
        cout << ans << "\n";
      } else {
        cout << ans - sr[q - 1] + sr[p - 1] + k * (q - p) << "\n";
      }
    } else {
      ll p = lower_bound(r.begin() + 1, r.end(), k) - r.begin();
      ll q = upper_bound(r.begin(), r.end(), k) - r.begin();
      p = max(p, k - x + 1);
      if (q <= p) {
        cout << ans << "\n";
      } else {
        cout << ans + ss[q - 1] - ss[p - 1] << "\n";
      }
    }
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