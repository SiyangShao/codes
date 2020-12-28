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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  ll l = 0, r = 1e16;
  function<bool(ll)> check = [&](ll x) {
    __int128 sum = 0;
    for (auto i : a) {
      sum += min(i, x);
    }
    __int128 ans = k;
    ans = ans * x;
    return ans <= sum;
  };

  ll ans = l;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      l = mid + 1;
      ans = max(ans, mid);
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
  // cin >> _;
  while (_--) {
    solve();
  }
}