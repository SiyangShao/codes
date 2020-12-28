#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n), need(n);
  for (auto &i : a) {
    cin >> i;
  }
  function<bool(ll)> check = [&](ll d) {
    for (int i = 0; i < n; ++i) {
      need[i] = (d + a[i] - 1) / a[i];
    }
    ll step = 0;
    for (int i = 0; i < n; ++i) {
      step += need[i];
    }
    return step <= m;
  };
  ll l = 0, r = 1e12;
  ll ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
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