#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll two(ll x) { return x * (x - 1) / 2; }
ll cal(ll c, ll k) {
  if (c < k) {
    return cal(c, c);
  }
  ll x = c / k, y = (c + k - 1) / k;
  if (x == y) {
    return k * (k - 1) / 2 * x * x;
  }
  ll n = c % k;
  return two(k - n) * x * x + two(n) * y * y + (k - n) * n * x * y;
}
auto solve() {
  int n;
  ll b, x;
  cin >> n >> b >> x;
  vector<int> c(n);
  for (auto &i : c)
    cin >> i;
  ll lef = 1, rig = *max_element(c.begin(), c.end());
  vector<ll> cst(rig + 1, -1);
  auto cost = [&](ll k) {
    if (cst[k] != -1) {
      return cst[k];
    }
    ll ans = -(k - 1) * x;
    for (auto i : c) {
      ans += cal(i, k) * b;
    }
    return cst[k] = ans;
  };
  // for (int i = 1; i <= rig; ++i) {
  //   cout << cost(i) << " ";
  // }
  // cout << "\n";
  // return;
  while (lef <= rig) {
    ll lmid = lef + (rig - lef) / 3;
    ll rmid = rig - (rig - lef) / 3;
    if (cost(lmid) <= cost(rmid)) {
      lef = lmid + 1;
    } else {
      rig = rmid - 1;
    }
  }
  lef = min(lef, (ll)*ranges::max_element(c));
  rig = max(rig, 1LL);
  cout << max(cost(lef), cost(rig)) << "\n";
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