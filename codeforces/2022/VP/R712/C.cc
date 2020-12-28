#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<pair<ll, ll>> v(n);
  for (auto &[a, c] : v) {
    cin >> a >> c;
    ans += c;
  }
  sort(v.begin(), v.end());
  // if i < j, v[j] to v[i] is free
  // if a[i] + c[i] > a[j], i to j is free
  // each path should go exactly once
  ll base = v[0].first + v[0].second;
  for (ll i = 1; i < n; ++i) {
    if (v[i].first <= base) {
      base = max(base, v[i].first + v[i].second);
      continue;
    } else {
      ans += v[i].first - base;
      base = max(base, v[i].first + v[i].second);
    }
  }
  cout << ans << "\n";
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