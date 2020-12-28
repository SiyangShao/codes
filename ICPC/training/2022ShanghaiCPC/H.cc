#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  auto cal = [&](ll len) {
    ll bs = len / k;
    if (len % k != 0) {
      bs++;
    }
    return bs;
  };
  for (auto &i : a) {
    cin >> i;
  }
  if (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())) {
    cout << cal(n) << "\n";
    return;
  }
  ll start = 0;
  for (ll i = 0; i < n; ++i) {
    if (a[i] != a[(i + 1) % n]) {
      start = (i + 1) % n;
      break;
    }
  }
  ll ans = 0, cnt = 1, mx = 1;
  for (ll i = start; i < start + n; ++i) {
    if (a[i % n] == a[(i + 1) % n]) {
      cnt++;
    } else {
      mx = max(mx, cnt);
      ans += cal(cnt);
      cnt = 1;
    }
  }
  if (mx >= k)
    cout << ans << "\n";
  else
    cout << "-1\n";
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