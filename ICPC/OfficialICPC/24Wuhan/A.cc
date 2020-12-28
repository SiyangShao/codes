#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
// ask if a[i][j] <= x
bool ask(ll i, ll j, ll x) {
  cout << "? " << i << " " << j << " " << x << endl;
  int y;
  cin >> y;
  return y == 1;
}
// calculate number of elements > x
ll cal(ll l, ll r, ll x, ll n, ll LEF, ll RIG) {
  if (l > r)
    return 0;
  ll m = (l + r) / 2;
  ll ans = 0;
  ll lef = max(LEF, 1LL), rig = min(RIG, n);
  // find the rightest element <= x
  ll result = max(LEF - 1, 0LL);
  while (lef <= rig) {
    ll mid = (lef + rig) / 2;
    if (ask(m, mid, x)) {
      // a[m][mid] <= x
      lef = mid + 1;
      result = max(result, mid);
    } else {
      rig = mid - 1;
    }
  }
  ans = n - result;
  return ans + cal(l, m - 1, x, n, result, RIG) +
         cal(m + 1, r, x, n, LEF, result);
}

auto solve() {
  ll n, k;
  cin >> n >> k;
  ll l = 1, r = n * n;
  ll ans = r;
  while (l <= r) {
    ll mid = (l + r) / 2;
    auto result = cal(1, n, mid, n, 1, n);
    // cerr << "l: " << l << "r " << r << "mid: " << mid << " result: " <<
    // result
    //  << endl;
    if (result >= k) {
      // mid is too small
      l = mid + 1;
    } else {
      ans = min(ans, mid);
      r = mid - 1;
    }
  }
  cout << "! " << ans << endl;
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