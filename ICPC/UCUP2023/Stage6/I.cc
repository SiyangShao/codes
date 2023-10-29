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
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), greater<>());
  ll l = 1, r = n;
  function<bool(ll)> check = [&](ll num) {
    priority_queue<ll> Q;
    for (ll i = 0; i < num; ++i) {
      Q.emplace(a[i] / 2);
    }
    for (ll i = num; i < n; ++i) {
      ll cur = Q.top();
      Q.pop();
      if (cur < a[i])
        return false;
      cur -= a[i];
      if (cur != 0)
        Q.emplace(cur);
      Q.emplace(a[i] / 2);
    }
    return true;
  };
  ll ans = n;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = min(ans, mid);
    } else {
      l = mid + 1;
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