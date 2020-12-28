#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  vector<pair<ll, ll>> dif(n);
  dif[0].first = dif[0].second = a[0];
  dif[n - 1].first = dif[n - 1].second = a[n - 1];
  for (ll i = 1; i + 1 < n; ++i) {
    ll large, small;
    if (a[i] <= s * 2) {
      large = min(s, a[i]);
      small = a[i] - large;
    } else {
      small = s;
      large = a[i] - s;
    }
    dif[i].first = small, dif[i].second = large;
  }
  ll prex = 0, prey = 0;
  for (ll i = 1; i < n; ++i) {
    ll nxtx, nxty;
    nxtx = min(prex + dif[i - 1].second * dif[i].first,
               prey + dif[i - 1].first * dif[i].first);
    nxty = min(prex + dif[i - 1].second * dif[i].second,
               prey + dif[i - 1].first * dif[i].second);
    prex = nxtx, prey = nxty;
  }
  cout << min(prex, prey) << "\n";
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