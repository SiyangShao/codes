#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e3;
auto solve() {
  ll s, k;
  cin >> s >> k;
  ll ans = s * k;
  if (k <= N) {
    for (ll i = 0; i < k; ++i) {
      ans = max(ans, s * (k - i));
      s += s % 10;
    }
    cout << ans << "\n";
    return;
  }
  if (s % 10 == 0) {
    cout << ans << "\n";
    return;
  }
  if (s % 10 == 5) {
    if (k == 1) {
      cout << ans << "\n";
    } else {
      cout << max(ans, (s + s % 10) * (k - 1)) << "\n";
    }
    return;
  }
  k--;
  s = s + s % 10;
  ll mid = (5 * k - s) / 10;
  ll lef = max(mid / 4 - 100, 0LL);
  ll sum = s + 20 * lef;
  ll res = k - lef * 4;
  // cout << mid << " ";
  for (ll i = 0; i < 1000; ++i) {
    ans = max(ans, sum * (res - i));
    sum += s % 10;
    s += s % 10;
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
