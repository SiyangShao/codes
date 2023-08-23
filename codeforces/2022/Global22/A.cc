#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);

  for (auto &i : a) {
    cin >> i;
  }
  vector<ll> b(n), l, r;
  for (ll i = 0; i < n; ++i) {
    cin >> b[i];
    if (a[i] == 0) {
      l.emplace_back(b[i]);
    } else {
      r.emplace_back(b[i]);
    }
  }
  if (l.empty()) {
    ll ans = 0;
    for (auto &i : r) {
      ans += i;
    }
    cout << ans << "\n";
  } else if (r.empty()) {
    ll ans = 0;
    for (auto &i : l) {
      ans += i;
    }
    cout << ans << "\n";
  } else {
    sort(l.begin(), l.end(), greater<>());
    sort(r.begin(), r.end(), greater<>());
    if (l.size() == r.size()) {
      ll ans = 0;
      for (ll i = 0; i + 1 < l.size(); ++i) {
        ans += l[i] * 2;
        ans += r[i] * 2;
      }
      ll L = l.back(), R = r.back();
      ans += max(L, R) * 2 + min(L, R);
      cout << ans << "\n";
    } else {
      ll sz = min(l.size(), r.size());
      ll ans = 0;
      for (ll i = 0; i < sz; ++i) {
        ans += l[i];
        ans += r[i];
      }
      for (auto &i : l) {
        ans += i;
      }
      for (auto &i : r) {
        ans += i;
      }
      cout << ans << "\n";
    }
  }
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